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

    vvi dp(n + 5, vi(2, -1));

    function<int(int, int)> dfs = [&](int curr, int prev)
    {
        if (curr == n)
            return 1LL;
        if (dp[curr][prev] == -1)
        {
            int total = 0;
            if (prev == 0)
            {
                for (int i = 1; i <= n; i += 2)
                {
                    if (curr + i > n)
                        break;
                    total += dfs(curr + i, 1);
                }
            }
            else
            {
                for (int i = 2; i <= n; i += 2)
                {
                    if (curr + i > n)
                        break;
                    total += dfs(curr + i, 0);
                }
            }
            dp[curr][prev] = total;
        }

        return dp[curr][prev];
    };

    cout << (dfs(0, 0) + dfs(0, 1)) % 1000000007 << endl;
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