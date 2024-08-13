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

bool ckmin(int &a, int b) { return b < a ? a = b, true : false; }

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

struct MCMF
{
    using F = int;
    using C = int; // flow type, cost type
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
        eds.pb({v, 0, cap, cost});
        adj[v].pb(eds.size());
        eds.pb({u, 0, 0, -cost});
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
                if (E.flo < E.cap && ckmin(dist[E.to], x.first + E.cost + p[x.second] - p[E.to]))
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

umap<char, int> dic;

void solve()
{
    string s, t;
    cin >> s >> t;
    MCMF mcmf;
    mcmf.init(54);

    for (int i = 0; i < 26; i++)
    {
        int curr = 0;
        for (int j = 0; j < 26; j++)
        {
            if (dic[t[j]] > dic[s[i]])
                curr += 2;
            else if (dic[t[j]] < dic[s[i]])
                curr += 1;
            if (dic[t[j]] > dic[s[i]])
            {
                mcmf.ae(j + 1, i + 27, 1, 0);
            }
            else if (dic[t[j]] == dic[s[i]])
            {
                mcmf.ae(j + 1, i + 27, 1, 1);
            }
            else
            {
                mcmf.ae(j + 1, i + 27, 1, 2);
            }
        }
    }

    for (int i = 1; i <= 26; i++)
    {
        mcmf.ae(0, i, 1, 0);
    }
    for (int i = 27; i <= 52; i++)
    {
        mcmf.ae(i, 53, 1, 0);
    }

    pii ans = mcmf.calc(0, 53);
    assert(ans.first == 26);

    cout << 52 - ans.second << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    dic['A'] = 14;
    dic['2'] = 2;
    dic['3'] = 3;
    dic['4'] = 4;
    dic['5'] = 5;
    dic['6'] = 6;
    dic['7'] = 7;
    dic['8'] = 8;
    dic['9'] = 9;
    dic['T'] = 10;
    dic['J'] = 11;
    dic['Q'] = 12;
    dic['K'] = 13;

    while (TC--)
    {
        solve();
    }

    return 0;
}