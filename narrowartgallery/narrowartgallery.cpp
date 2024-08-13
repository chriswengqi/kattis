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
    int n, kk;
    cin >> n >> kk;

    vvi arr(n, vi(2, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    int _;
    cin >> _ >> _;

    vector<vvi> dp(n + 1, vvi(kk + 1, vi(4, -1)));

    function<int(int, int, int)> dfs = [&](int curr, int k, int prev)
    {
        if (curr == n)
        {
            if (k > 0)
                return -(int)LLINF;
            else
                return 0LL;
        }

        if (dp[curr][k][prev] != -1)
            return dp[curr][k][prev];
        // don't close anything
        int ans = arr[curr][0] + arr[curr][1] + dfs(curr + 1, k, 0);
        // close left if prev not 2
        if (k > 0)
        {
            if (prev != 2)
            {
                ans = max(ans, arr[curr][1] + dfs(curr + 1, k - 1, 1));
            }
            // close right if prev not 1
            if (prev != 1)
            {
                ans = max(ans, arr[curr][0] + dfs(curr + 1, k - 1, 2));
            }
        }
        debug(curr);
        debug(k);
        debug(prev);
        debug(ans);
        // return ans;
        return dp[curr][k][prev] = ans;
    };

    cout
        << dfs(0, kk, 0) << endl;
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