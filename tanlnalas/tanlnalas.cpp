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

void solve()
{
    int n, m;
    cin >> n >> m;
    string src, dst;
    cin >> src >> dst;
    vs arr(m + 2);
    arr[0] = src;
    arr[m + 1] = dst;
    for (int i = 1; i <= m; i++)
    {
        cin >> arr[i];
    }
    vvi adj(m + 2, vi());
    for (int i = 0; i < m + 2; i++)
    {
        for (int j = i + 1; j < m + 2; j++)
        {
            int diff = 0;
            for (int k = 0; k < n; k++)
            {
                int a = abs((int)(arr[i][k] - arr[j][k]));
                diff += (a == 9 ? 1 : a);
            }
            assert(diff != 0);
            if (diff == 1)
            {

                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    // for (int i = 0; i < m + 2; i++)
    // {
    //     for (int v : adj[i])
    //     {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    vi ans;
    vi stack;
    vi visited(m + 2, 0);
    function<void(int)> dfs = [&](int u)
    {
        if (arr[u] == dst)
        {
            if (ans.size() == 0 || stack.size() < ans.size())
            {
                ans = stack;
            }
            return;
        }
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                stack.pb(v);
                visited[v] = 1;
                dfs(v);
                visited[v] = 0;
                stack.pop_back();
            }
        }
    };
    dfs(0);
    if (ans.size() == 0)
    {
        cout << "Neibb" << endl;
    }
    else
    {
        cout << ans.size() << endl;
        cout << src << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << arr[ans[i]] << endl;
        }
    }
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