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

    vpii arr(n);
    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        arr[i] = {s, t};
    }

    vvi dp(n + 1, vi(k + 1, -1));

    function<int(int, int, int)> dfs = [&](int curr, int w, int h)
    {
        if (curr == n)
            return h;
        // add to new line
        if (dp[curr][w] != -1)
            return dp[curr][w];
        int ans = h + dfs(curr + 1, arr[curr].first, arr[curr].second);
        if (w + arr[curr].first <= k)
        {
            ans = min(ans, dfs(curr + 1, w + arr[curr].first, max(h, arr[curr].second)));
        }
        return dp[curr][w] = ans;
    };

    cout << dfs(1, arr[0].first, arr[0].second) << endl;
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