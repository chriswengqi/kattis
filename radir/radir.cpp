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
    vvi grid(4, vi(17, 0));

    if (k < 3)
    {
        cout << "Neibb" << endl;
        return 0;
    }

    for (int i = 0; i < k; i++)
    {
        int p, q;
        cin >> p >> q;
        grid[p - 1][q] = 1;
        if ((grid[p - 1][q] & grid[p - 1][q + 1] & grid[p - 1][q + 2]) || (grid[p - 1][q] & grid[p - 1][q + 1] & grid[p - 1][q - 1]) || (grid[p - 1][q] & grid[p - 1][q - 1] & grid[p - 1][q - 2]))
        {
            cout << 0 << endl;
            return 0;
        }
    }

    for (int i = 1; i <= n - k; i++)
    {
        int p, q;
        cin >> p >> q;
        q++;
        grid[p - 1][q] = 1;
        if ((grid[p - 1][q] & grid[p - 1][q + 1] & grid[p - 1][q + 2]) || (grid[p - 1][q] & grid[p - 1][q + 1] & grid[p - 1][q - 1]) || (grid[p - 1][q] & grid[p - 1][q - 1] & grid[p - 1][q - 2]))
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << "Neibb" << endl;

    return 0;
}
