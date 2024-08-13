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

typedef tuple<int, ll, ll, ll> edge2;

class min_cost_max_flow
{
private:
    int V;
    ll total_cost;
    vector<edge2> EL2;
    vector<vi> AL2;
    vi d;
    vi last, vis;

    bool SPFA(int s, int t)
    { // SPFA to find augmenting path in residual graph
        d.assign(V, INF);
        d[s] = 0;
        vis[s] = 1;
        queue<int> q({s});
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for (auto &idx : AL2[u])
            {                                          // explore neighbors of u
                auto &[v, cap, flow, cost] = EL2[idx]; // stored in EL2[idx]
                if ((cap - flow > 0) && (d[v] > d[u] + cost))
                { // positive residual edge2
                    d[v] = d[u] + cost;
                    if (!vis[v])
                        q.push(v), vis[v] = 1;
                }
            }
        }
        return d[t] != INF; // has an augmenting path
    }

    ll DFS(int u, int t, ll f = INF)
    { // traverse from s->t
        if ((u == t) || (f == 0))
            return f;
        vis[u] = 1;
        for (int &i = last[u]; i < (int)AL2[u].size(); ++i)
        { // from last edge2
            auto &[v, cap, flow, cost] = EL2[AL2[u][i]];
            if (!vis[v] && d[v] == d[u] + cost)
            { // in current layer graph
                if (ll pushed = DFS(v, t, min(f, cap - flow)))
                {
                    total_cost += pushed * cost;
                    flow += pushed;
                    auto &[rv, rcap, rflow, rcost] = EL2[AL2[u][i] ^ 1]; // back edge2
                    rflow -= pushed;
                    vis[u] = 0;
                    return pushed;
                }
            }
        }
        vis[u] = 0;
        return 0;
    }

public:
    min_cost_max_flow(int initialV) : V(initialV), total_cost(0)
    {
        EL2.clear();
        AL2.assign(V, vi());
        vis.assign(V, 0);
    }

    // if you are adding a bidirectional edge2 u<->v with weight w into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll w, ll c, bool directed = true)
    {
        if (u == v)
            return;                       // safeguard: no self loop
        EL2.emplace_back(v, w, 0, c);     // u->v, cap w, flow 0, cost c
        AL2[u].push_back(EL2.size() - 1); // remember this index
        EL2.emplace_back(u, 0, 0, -c);    // back edge2
        AL2[v].push_back(EL2.size() - 1); // remember this index
        if (!directed)
            add_edge(v, u, w, c); // add again in reverse
    }

    pair<ll, ll> mcmf(int s, int t)
    {
        ll mf = 0; // mf stands for max_flow
        while (SPFA(s, t))
        {                            // an O(V^2*E) algorithm
            last.assign(V, 0);       // important speedup
            while (ll f = DFS(s, t)) // exhaust blocking flow
                mf += f;
        }
        return {mf, total_cost};
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int p, r, l;
    cin >> p >> r >> l;

    min_cost_max_flow mf(r + 4);

    for (int i = 0; i < l; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u < 0)
        {
            u += r + 2;
        }
        if (v < 0)
        {
            v += r + 2;
        }

        mf.add_edge(u, v, 1, 1, false);
    }
    mf.add_edge(r + 2, r, p, 0);
    mf.add_edge(r + 1, r + 3, p, 0);

    auto ans = mf.mcmf(r, r + 1);

    if (ans.first != p)
    {

        cout << p - ans.first << " people left behind" << endl;
    }
    else
    {
        cout << ans.second << endl;
    }

    return 0;
}