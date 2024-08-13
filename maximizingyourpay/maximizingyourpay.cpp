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
#define sz(x) (int)x.size()
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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m)
    {
        vector<uset<int>> adj(n, uset<int>());
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        vvi dp(n + 1, vi(1 << n, -1));

        function<int(int, int)> dfs = [&](int u, int bitmask)
        {
            if (u == 0 && bitmask != 0)
            {
                return (int)__builtin_popcount(bitmask | 1);
            }
            if (dp[u][bitmask] != -1)
            {
                return dp[u][bitmask];
            }
            int ans = 0;
            for (int v : adj[u])
            {
                if (!((1 << v) & bitmask))
                {
                    ans = max(ans, dfs(v, bitmask | (1 << v)));
                }
            }
            return dp[u][bitmask] = ans;
        };

        int ans = dfs(0, 0);
        cout << (ans == 0 ? 1 : ans) << endl;
    }

    return 0;
}