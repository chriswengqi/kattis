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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vi arr(n);

    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        arr[i] = s * 100 - k * (n - i);
    }

    int ans = 0;
    int max_prices = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_prices)
        {
            max_prices = arr[i];
        }
        else
        {
            ans = max(ans, max_prices - arr[i]);
        }
    }

    cout << ans - k << endl;

    return 0;
}
