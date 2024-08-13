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

    int m, p, n;
    cin >> m >> p >> n;
    int curr = m;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        if (w >= curr)
        {
            ans++;
        }
        cout << -100 / 100 << endl;
        curr = m + (curr - w) * p / 100 + (((curr - w) * p) % 100 != 0 ? 1 : 0);

        cout << curr << endl;
    }

    cout << ans << endl;

    return 0;
}
