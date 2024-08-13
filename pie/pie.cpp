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

void solve()
{
    int n, f;
    cin >> n >> f;
    vd arr(n);
    for (int i = 0; i < n; i++)
    {
        double s;
        cin >> s;
        arr[i] = s * s * M_PI;
    }

    double left = 0.001;
    double right = *max_element(arr.begin(), arr.end());

    while (right - left > 1e-6)
    {
        double mid = (left + right) / 2;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += (int)(arr[i] / mid);
        }
        if (total < f + 1)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

    cout << fixed << setprecision(6) << left << endl;
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
