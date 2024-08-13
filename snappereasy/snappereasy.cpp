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
    int n, k;
    cin >> n >> k;
    int bitmask = k % (1 << n);
    if (bitmask == (1 << n) - 1)
    {
        cout << "ON" << endl;
    }
    else
    {
        cout << "OFF" << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    for (int i = 1; i <= TC; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
