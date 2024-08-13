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
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

void solve()
{
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n != 0)
    {
        vi arr(n);
        vi dp(n, 1);
        IT(i, n)
        {
            cin >> arr[i];
        }

        int maxx = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    maxx = max(dp[i], maxx);
                }
            }
        }

        vi ans;

        cout << maxx << " ";

        for (int i = n - 1; i >= 0; i--)
        {
            if (dp[i] == maxx)
            {
                ans.pb(arr[i]);
                maxx--;
            }
        }

        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }

        cout << endl;

        cin >> n;
    }

    return 0;
}
