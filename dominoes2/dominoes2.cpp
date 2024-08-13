#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

void solve()
{
    int n, m, l;
    cin >> n >> m >> l;
    vvi adj(n + 1, vi());

    vi knocked(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    for (int i = 0; i < l; i++)
    {
        int s;
        cin >> s;
        if (knocked[s] == 0)
        {
            // bfs
            deque<int> dq;
            dq.pb(s);
            knocked[s] = 1;

            while (dq.size() > 0)
            {
                int curr = dq.front();
                dq.pop_front();
                for (int v : adj[curr])
                {
                    if (knocked[v] == 0)
                    {
                        dq.pb(v);
                        knocked[v] = 1;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int a : knocked)
    {
        ans += a;
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        solve();
    }

    return 0;
}
