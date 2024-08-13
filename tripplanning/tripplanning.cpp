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

    int n, m;
    cin >> n >> m;
    vi arr(n, -1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        int u = min(a, b);
        int v = max(a, b);
        if (v == n & u == 1)
            arr[n - 1] = i;
        if (v == u + 1)
        {
            arr[u - 1] = i;
        }
    }

    for (int a : arr)
    {
        if (a == -1)
        {
            cout << "impossible" << endl;
            return 0;
        }
    }

    for (int a : arr)
    {
        cout << a << endl;
    }

    return 0;
}
