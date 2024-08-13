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

    long double ans = 1;
    long double n;
    cin >> n;

    n = min(n, (long double)17);

    for (int i = 1; i <= n; i++)
    {
        ans += 1 / (long double)factorial(i);
    }

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}
