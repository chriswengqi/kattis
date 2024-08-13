#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
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

    int n;
    cin >> n;

    double x_sum = 0;
    double y_sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x_sum += x;
        y_sum += y;
    }

    cout << fixed << setprecision(10) << (y_sum - x_sum) / (double)n << endl;

    return 0;
}
