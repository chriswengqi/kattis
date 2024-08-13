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

int factorial(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n > 13)
    {
        cout << fixed << setprecision(10) << 0.6321205588 << endl;
        return 0;
    }
    double ans = 0;
    double sign = 1;

    for (int i = 1; i <= n; i++)
    {
        ans += sign * 1 / (double)factorial(i);
        sign *= -1;
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
