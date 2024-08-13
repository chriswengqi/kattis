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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vi arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vvi dp(n + 1, vi(2001, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i < 2001; i++)
        {
            dp[j][i] |= dp[j - 1][i];
            if (i >= arr[j - 1] && dp[j - 1][i - arr[j - 1]] == 1)
            {
                dp[j][i] |= dp[j - 1][i - arr[j - 1]];
            }
        }
    }

    int ans = 0;
    int min_abs = 2000;

    for (int i = 0; i < 2001; i++)
    {
        if (dp[n][i] == 1 && abs(i - 1000) <= min_abs)
        {
            ans = i;
            min_abs = abs(i - 1000);
        }
    }

    cout << ans << endl;

    return 0;
}
