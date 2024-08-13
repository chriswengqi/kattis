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
    cin >> k >> n;
    vvi prices(n + 1, vi());
    vvi tix(n + 1, vi());
    for (int i = 0; i <= n; i++)
    {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++)
        {
            int t;
            cin >> t;
            prices[i].pb(t);
        }

        for (int j = 0; j < s; j++)
        {
            int t;
            cin >> t;
            tix[i].pb(t);
        }
    }

    vvi dp(n + 2, vi(k + 1, -1));

    function<int(int, int)> dfs = [&](int curr, int rem)
    {
        if (rem == 0 || curr == n + 1)
            return 0LL;
        if (dp[curr][rem] != -1)
            return dp[curr][rem];
        int total = 0;
        for (int i = 0; i < prices[curr].size(); i++)
        {
            total = max(total, prices[curr][i] * min(tix[curr][i], rem) + dfs(curr + 1, max(0LL, rem - tix[curr][i])));
        }
        return dp[curr][rem] = total;
    };
    int ans = 0;
    int set_price = 0;
    for (int i = 0; i < prices[0].size(); i++)
    {
        int ttl = prices[0][i] * min(tix[0][i], k) + dfs(1, max(0LL, k - tix[0][i]));
        if (ttl > ans)
        {
            ans = ttl;
            set_price = prices[0][i];
        }
    }

    cout << ans << endl;
    cout << set_price << endl;
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