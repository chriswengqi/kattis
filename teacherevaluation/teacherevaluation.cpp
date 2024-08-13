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

    int n, k;
    cin >> n >> k;
    int val = 0;

    vi arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        val += arr[i];
    }

    if (k == 100)
    {
        cout << "impossible" << endl;
    }
    else
    {
        int ans = (k * n - val) / (100 - k);
        if ((k * n - val) % (100 - k) != 0)
            ans++;
        cout << ans << endl;
    }

    return 0;
}
