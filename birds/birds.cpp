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

    int l, d, n;
    cin >> l >> d >> n;
    vi arr;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        arr.pb(s);
    }
    arr.pb(6 - d);     // dummy birds
    arr.pb(l - 6 + d); // dummy birds
    sort(arr.begin(), arr.end());
    int ans = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        int diff = arr[i] - arr[i - 1];
        ans += max(0LL, (diff - d) / d);
    }

    cout << ans << endl;

    return 0;
}
