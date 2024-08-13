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
    vpdd arr;

    for (int i = 0; i < n; i++)
    {
        double x, z;
        cin >> x >> z;
        arr.pb({x, z});
    }

    sort(arr.begin(), arr.end());

    double ans = 0;

    for (int i = 1; i < n; i++)
    {
        double grad = abs((arr[i].second - arr[i - 1].second) / (arr[i].first - arr[i - 1].first));
        ans = max(ans, grad);
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
