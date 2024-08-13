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
    vi xs(n);
    vi ys(n);

    for (int i = 0; i < n; i++)
    {
        cin >> xs[i];
        cin >> ys[i];
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    for (int i = 1; i < n; i++)
    {
        xs[i] += xs[i - 1];
        ys[i] += ys[i - 1];
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += (xs[i] - xs[i - 1]) * i - xs[i - 1];
        ans += (ys[i] - ys[i - 1]) * i - ys[i - 1];
    }

    cout << ans << endl;

    return 0;
}
