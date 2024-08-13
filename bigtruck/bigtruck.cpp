#include <bits/stdc++.h>

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

void solve()
{
    int n;
    cin >> n;
    vi items(n);
    for (int i = 0; i < n; i++)
        cin >> items[i];
    int m;
    cin >> m;
    vi sp(n, INF);
    vi dp(n, INF);
    vector<vpii> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({0, 0, 0}); // dist, curr, items_picked
    sp[0] = 0;
    dp[0] = items[0];
    // sort the pairs by non-decreasing distance from s
    while (!pq.empty())
    { // main loop
        auto [d, u, ttl] = pq.top();
        pq.pop(); // shortest unvisited u

        if (d > sp[u])
            continue; // a very important check
        for (auto [v, w] : adj[u])
        { // all edges from u
            if (sp[u] + w >= sp[v])
                continue;
            sp[v] = sp[u] + w;
            pq.push({sp[v], v});
        }
    }

    if (sp[n - 1] == INF)
    {
        cout << "impossible" << endl;
        return;
    }

    cout << sp[n - 1] << " " << ans + items[n - 1] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    TC = 1;

    while (TC--)
    {
        solve();
    }

    return 0;
}