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
    vs grid(n);

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    vvi dp(n, vi(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '#')
            {
                continue;
            }
            if (i - 1 >= 0)
            {
                dp[i][j] += dp[i - 1][j];
            }
            if (j - 1 >= 0)
            {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    if (dp[n - 1][n - 1] != 0)
    {
        cout << dp[n - 1][n - 1] << endl;
    }
    else
    {
        cout << "THE GAME IS A LIE" << endl;
    }

    return 0;
}
