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

map<pii, int> dic;

int dp(int n, int k)
{
    if (k == 1)
    {
        return n;
    }

    int ans = 1e9;

    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, max(dp(n - 1, k - 1), dp(n - i, k)));
    }

    cout << n << " " << k << " " << ans << endl;

    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    cout << dp(n, k) << endl;
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
