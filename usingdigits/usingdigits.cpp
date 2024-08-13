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
    int n, k;
    cin >> n >> k;
    string key;
    cin >> key;
    vs grid(k);

    for (int i = 0; i < k; i++)
    {
        cin >> grid[i];
    }

    vector<vvi> dp(k + 5, vvi(n + 5, vi(key.size() + 5, -1)));

    function<int(int, int, int)> dfs = [&](int x, int y, int c)
    {
        if (x == 0 && y == n - 1)
            return (int)(grid[x][y] - '0');
        // up, right, hop up, hop right
        if (dp[x][y][c] != -1)
            return dp[x][y][c];
        int ans = LLINF;
        int curr = (int)(grid[x][y] - '0');
        if (x > 0)
            ans = min(ans, curr + dfs(x - 1, y, c));
        if (y < n - 1)
            ans = min(ans, curr + dfs(x, y + 1, c));
        if (c != key.size())
        {
            int curr_key = (int)(key[c] - '0');
            if (x > curr_key)
            {
                ans = min(ans, curr + dfs(x - curr_key - 1, y, c + 1));
            }
            if (y < n - 1 - curr_key)
            {
                ans = min(ans, curr + dfs(x, y + curr_key + 1, c + 1));
            }
        }
        return dp[x][y][c] = ans;
    };

    cout << dfs(k - 1, 0, 0) << endl;
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