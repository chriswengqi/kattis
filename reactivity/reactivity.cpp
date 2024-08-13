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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<uset<int>> adj;

    int n, m;
    cin >> n >> m;
    vi indeg(n + 1, 0);
    adj.resize(n + 1, uset<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (!adj[a].count(b))
        {
            adj[a].insert(b);
            indeg[b]++;
        }
    }
    vi dp(n + 1, 1);
    vi parent(n + 1, -1);
    vi visited(n + 1, 0);
    queue<iii> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push({i, 1, -1});
            visited[i] = 1;
        }
    }
    vi top_sort;
    while (q.size() > 0)
    {
        auto [u, dist, par] = q.front();
        top_sort.pb(u);
        if (dist > dp[u])
        {
            dp[u] = dist;
            parent[u] = par;
        }
        q.pop();
        for (int v : adj[u])
        {
            indeg[v]--;
            if (indeg[v] == 0)
            {
                if (visited[v])
                {
                    cout << "back to the lab" << endl;
                    return 0;
                }
                visited[v] = 1;
                q.push({v, dist + 1, u});
            }
        }
    }
    if (top_sort.size() != n)
    {
        cout << "back to the lab" << endl;
        return 0;
    }

    int ans = 1;
    int best = 1;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
            best = i;
        }
    }

    if (ans != n)
    {
        cout << "back to the lab" << endl;
        return 0;
    }

    vi op;
    while (best != -1)
    {
        op.pb(best);
        best = parent[best];
    }
    for (int i = ans - 1; i >= 0; i--)
    {
        cout << op[i] << " ";
    }
    cout << endl;

    return 0;
}