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

typedef tuple<int, ll, ll> edge;
class max_flow
{
public:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    umap<int, int> edge_map;
    vi d, last;
    vector<pii> p;

    bool BFS(int s, int t)
    { // find augmenting path
        d.assign(V, -1);
        d[s] = 0;
        queue<int> q({s});
        p.assign(V, {-1, -1}); // record BFS sp tree
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == t)
                break; // stop as sink t reached
            for (auto &idx : AL[u])
            {                                                    // explore neighbors of u
                auto &[v, cap, flow] = EL[idx];                  // stored in EL[idx]
                if ((cap - flow > 0) && (d[v] == -1))            // positive residual edge
                    d[v] = d[u] + 1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
            }
        }
        return d[t] != -1; // has an augmenting path
    }

    ll send_one_flow(int s, int t, ll f = INF)
    { // send one flow from s->t
        if (s == t)
            return f; // bottleneck edge f found
        auto &[u, idx] = p[t];
        auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
        ll pushed = send_one_flow(s, u, min(f, cap - flow));
        flow += pushed;
        auto &rflow = get<2>(EL[idx ^ 1]); // back edge
        rflow -= pushed;                   // back flow
        return pushed;
    }

    ll DFS(int u, int t, ll f = INF)
    { // traverse from s->t
        if ((u == t) || (f == 0))
            return f;
        for (int &i = last[u]; i < (int)AL[u].size(); ++i)
        { // from last edge
            auto &[v, cap, flow] = EL[AL[u][i]];
            if (d[v] != d[u] + 1)
                continue; // not part of layer graph
            if (ll pushed = DFS(v, t, min(f, cap - flow)))
            {
                flow += pushed;
                auto &rflow = get<2>(EL[AL[u][i] ^ 1]); // back edge
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    max_flow(int initialV) : V(initialV)
    {
        EL.clear();
        AL.assign(V, vi());
    }

    // if you are adding a bidirectional edge u<->v with weight w into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll w, bool directed = true)
    {
        if (u == v)
            return;                     // safeguard: no self loop
        EL.emplace_back(v, w, 0);       // u->v, cap w, flow 0
        AL[u].push_back(EL.size() - 1); // remember this index
        edge_map[u * V + v] = EL.size() - 1;
        EL.emplace_back(u, directed ? 0 : w, 0); // back edge
        AL[v].push_back(EL.size() - 1);          // remember this index
        edge_map[v * V + u] = EL.size() - 1;
    }

    ll edmonds_karp(int s, int t)
    {
        ll mf = 0; // mf stands for max_flow
        while (BFS(s, t))
        {                               // an O(V*E^2) algorithm
            ll f = send_one_flow(s, t); // find and send 1 flow f
            if (f == 0)
                break; // if f == 0, stop
            mf += f;   // if f > 0, add to mf
        }
        return mf;
    }

    ll dinic(int s, int t)
    {
        ll mf = 0; // mf stands for max_flow
        while (BFS(s, t))
        {                            // an O(V^2*E) algorithm
            last.assign(V, 0);       // important speedup
            while (ll f = DFS(s, t)) // exhaust blocking flow
                mf += f;
        }
        return mf;
    }

    umap<int, int> get_edge_map()
    {
        return edge_map;
    }
};

bool dist(double x1, double x2, double y1, double y2, double d)
{
    // debug((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= d * d;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double d;
    cin >> n >> d;
    int ttl = 0;
    vi op;

    vector<tuple<double, double, int, int>> arr;

    for (int i = 0; i < n; i++)
    {
        int c, d;
        double a, b;
        cin >> a >> b >> c >> d;
        ttl += c;
        arr.pb({a, b, c, d});
    }

    for (int i = 1; i <= n; i++)
    {
        // 0, i -> in vertices, i + n -> out vertice
        max_flow mf(n * 2 + 2);

        mf.add_edge(i, n * 2 + 1, ttl);

        for (int j = 1; j <= n; j++)
        {
            mf.add_edge(0, j, get<2>(arr[j - 1]));
        }

        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                // debug(i);
                // debug(j);
                if (dist(get<0>(arr[j]), get<0>(arr[k]), get<1>(arr[j]), get<1>(arr[k]), d))
                {
                    // cout << "Here" << endl;
                    mf.add_edge(j + n + 1, k + 1, INF);
                    mf.add_edge(k + n + 1, j + 1, INF);
                }
            }
        }

        for (int j = 1; j <= n; j++)
        {
            mf.add_edge(j, j + n, get<3>(arr[j - 1]));
        }

        int ans = mf.dinic(0, n * 2 + 1);
        // debug(i);
        // debug(ans);

        if (ans == ttl)
        {
            op.pb(i - 1);
        }
    }

    if (op.size() == 0)
        cout << -1 << endl;
    else
    {
        for (int a : op)
            cout << a << " ";
    }

    return 0;
}