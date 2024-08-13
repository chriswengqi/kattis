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
    vector<pair<int, double>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int p;
        double q;
        cin >> p >> q;

        arr[i] = {p, q / 100};
    }

    vvd dp(n + 1, vd(151, -1));

    function<double(int, int)> dfs = [&](int idx, int curr)
    {
        if (idx == n)
        {
            if (curr >= 76)
            {
                return 1.0;
            }
            else
            {
                return 0.0;
            }
        }

        if (dp[idx][curr] != -1)
            return dp[idx][curr];

        return dp[idx][curr] = max(arr[idx].second * dfs(idx + 1, curr + arr[idx].first), dfs(idx + 1, curr));
    };

    cout << fixed << setprecision(10) << dfs(0, 0) * 100 << endl;
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