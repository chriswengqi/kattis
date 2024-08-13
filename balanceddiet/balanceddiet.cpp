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

    while (n != 0)
    {
        vi arr(n);
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            total += arr[i];
        }

        vvi dp(n + 1, vi(total / 2 + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= total / 2; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (arr[i - 1] <= j)
                {
                    dp[i][j] |= dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        for (int i = total / 2; i >= 0; i--)
        {
            if (dp[n][i] == 1)
            {
                cout << total - i << " " << i << endl;
                break;
            }
        }

        cin >> n;
    }

    return 0;
}
