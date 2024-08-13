#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
typedef tuple<int, int, int> iii;

#define pb push_back
#define em emplace
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define INF 1e9
#define LLINF 4e18
#define umap unordered_map
#define uset unordered_set
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
#define debug1(a)                           \
    for (int i = 0; i <= a.size() - 1; i++) \
    cout << a[i] << (i == a.size() - 1 ? '\n' : ' ')
#define debug2(a)                                  \
    for (int i = 0; i <= a.size() - 1; i++)        \
        for (int j = 0; j <= a[0].size() - 1; j++) \
    cout << a[i][j] << (j == a[0].size() - 1 ? '\n' : ' ')

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool ckmin(double &a, double b) { return b < a ? a = b, true : false; }

bool ckmax(int &a, int b) { return b > a ? a = b, true : false; }

double EPS = 1e-9;

struct MCMF
{
    using F = double;
    using C = double; // flow type, cost type
    struct Edge
    {
        int to;
        F flo, cap;
        C cost;
    };
    int N;
    vector<C> p, dist;
    vi pre;
    vector<Edge> eds;
    vector<vi> adj;
    void init(int _N)
    {
        N = _N;
        p.resize(N), dist.resize(N), pre.resize(N), adj.resize(N);
    }
    void ae(int u, int v, F cap, C cost)
    {
        assert(cap >= 0);
        adj[u].pb(eds.size());
        eds.pb({v, 0.0, cap, cost});
        adj[v].pb(eds.size());
        eds.pb({u, 0.0, 0.0, -cost});
    } // use asserts, don't try smth dumb
    bool path(int s, int t)
    { // find lowest cost path to send flow through
        const C inf = numeric_limits<C>::max();
        for (int i = 0; i < N; i++)
            dist[i] = inf;
        using T = pair<C, int>;
        priority_queue<T, vector<T>, greater<T>> todo;
        todo.push({dist[s] = 0, s});
        while (todo.size())
        { // Dijkstra
            T x = todo.top();
            todo.pop();
            if (x.first > dist[x.second])
                continue;
            for (auto e : adj[x.second])
            {
                const Edge &E = eds[e]; // all weights should be non-negative
                if (E.flo < E.cap && ckmin(dist[E.to], x.first + E.cost + EPS + p[x.second] - p[E.to]))
                    pre[E.to] = e, todo.push({dist[E.to], E.to});
            }
        } // if costs are doubles, add some EPS so you
        // don't traverse ~0-weight cycle repeatedly
        return dist[t] != inf; // return flow
    }
    pair<F, C> calc(int s, int t)
    {
        assert(s != t);
        for (int i = 0; i < N; i++)
        {
            for (int e = 0; e < eds.size(); e++)
            {
                const Edge &E = eds[e]; // Bellman-Ford
                if (E.cap)
                    ckmin(p[E.to], p[eds[e ^ 1].to] + E.cost);
            }
        }

        F totFlow = 0;
        C totCost = 0;
        while (path(s, t))
        { // p -> potentials for Dijkstra
            for (int i = 0; i < N; i++)
                p[i] += dist[i]; // don't matter for unreachable nodes
            F df = numeric_limits<F>::max();
            for (int x = t; x != s; x = eds[pre[x] ^ 1].to)
            {
                const Edge &E = eds[pre[x]];
                ckmin(df, E.cap - E.flo);
            }
            totFlow += df;
            totCost += (p[t] - p[s]) * df;
            for (int x = t; x != s; x = eds[pre[x] ^ 1].to)
                eds[pre[x]].flo += df, eds[pre[x] ^ 1].flo -= df;
        } // get max flow you can send along path
        return {totFlow, totCost};
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s, t;
    double q;
    cin >> n >> s >> t >> q;

    vector<tuple<double, double, double>> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        double x, y, z;
        cin >> x >> y >> z;
        arr[i] = {x, y, z};
    }

    uset<int> towns;
    uset<int> springs;
    for (int i = 0; i < s; i++)
    {
        int r;
        cin >> r;
        springs.insert(r);
    }
    for (int i = 0; i < t; i++)
    {
        int r;
        cin >> r;
        towns.insert(r);
    }

    MCMF mcmf;
    mcmf.init(n + 2);
    // add from non town to every where else
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (get<2>(arr[i]) > get<2>(arr[j]))
            {
                double dist = (get<0>(arr[i]) - get<0>(arr[j])) * (get<0>(arr[i]) - get<0>(arr[j])) + (get<1>(arr[i]) - get<1>(arr[j])) * (get<1>(arr[i]) - get<1>(arr[j])) + (get<2>(arr[i]) - get<2>(arr[j])) * (get<2>(arr[i]) - get<2>(arr[j]));
                if (dist <= q * q)
                {
                    mcmf.ae(i, j, n, sqrt(dist));
                }
            }
        }
    }

    for (int a : towns)
    {
        mcmf.ae(a, n + 1, 1, 0);
    }

    for (int b : springs)
    {
        mcmf.ae(0, b, 1, 0);
    }

    pair<double, double> ans = mcmf.calc(0, n + 1);

    if ((int)ans.first != t)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << fixed << setprecision(10) << ans.second << endl;
    }

    return 0;
}