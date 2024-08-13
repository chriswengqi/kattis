#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair
#define M_PI 3.14159265358979323846

void solve()
{
    double r, n;
    cin >> r >> n;

    if (n == 1)
    {
        cout << fixed << setprecision(10) << M_PI * r * r << endl;
        return;
    }

    double circle = r * r / 4;
    double ans = M_PI * r * r + 4 * M_PI * circle;
    int curr = 3;
    for (int i = 3; i <= n; i++)
    {
        double add = curr * M_PI * circle;
        ans += add;
        circle *= r / 2;

        curr *= 4;
    }

    cout << fixed << setprecision(10) << ans << endl;
}

int main()
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
