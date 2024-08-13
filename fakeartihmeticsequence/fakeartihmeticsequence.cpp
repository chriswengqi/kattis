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
    vi dp(n, 0);

    for (int &a : arr)
    {
        cin >> a;
    }
    int ans = 0;
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (arr[k] + arr[j] == arr[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(dp[i], ans);
                }
            }
        }
    }

    for (int a : dp)
    {
        cout << a << " ";
    }

    cout << endl;

    cout << ans + 2 << endl;

    return 0;
}
