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
    int n, n1, n5, n10;
    cin >> n >> n1 >> n5 >> n10;
    int ttl = n1 + n5 * 5 + n10 * 10;
    // n1 = ttl - n5 * 5 - n10 * 10 - a * 8;
    vector<vvi> dp(n + 1, vvi(n5 + n10 + 1, vi(n10 + 1, -1)));
    function<int(int, int, int)> dfs = [&](int a, int b, int c)
    {
        if (a == n)
            return 0LL;
        // how to buy ? (10), {5,5}, {5,1,1,1}, {1 * 8}
        if (dp[a][b][c] != -1)
            return dp[a][b][c];
        int ans = LLINF;
        if (c > 0)
        {
            ans = min(ans, 1 + dfs(a + 1, b, c - 1));
        }
        if (b > 1)
        {
            ans = min(ans, 2 + dfs(a + 1, b - 2, c));
        }
        if (ttl - b * 5 - c * 10 - a * 8 >= 3 && b > 0)
        {
            ans = min(ans, 4 + dfs(a + 1, b - 1, c));
        }
        if (ttl - b * 5 - c * 10 - a * 8 >= 3 && c > 0)
        {
            ans = min(ans, 4 + dfs(a + 1, b + 1, c - 1));
        }
        if (ttl - b * 5 - c * 10 - a * 8 >= 8)
        {
            ans = min(ans, 8 + dfs(a + 1, b, c));
        }

        return dp[a][b][c] = ans;
    };

    cout << dfs(0, n5, n10) << endl;
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