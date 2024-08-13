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

bool is_symmetric(vvi &grid, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(grid[i][j]) != abs(grid[j][i]))
            {
                return false;
            }
        }
    }
    return true;
}

void print_matrix(vvi &grid, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vvi grid(n, vi(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    if (is_symmetric(grid, n))
    {
        cout << 1 << endl;
        print_matrix(grid, n);
        return 0;
    }

    vvi new_grid(n, vi(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (abs((grid[i][j] + grid[j][i])) % 2 == 1)
            {
                cout << -1 << endl;
                return 0;
            }
            if (abs(grid[i][j]) != abs(grid[j][i]))
            {
                int mid = (grid[i][j] + grid[j][i]) / 2;
                int diff = grid[i][j] - mid;
                grid[i][j] = grid[j][i] = mid;
                new_grid[i][j] = diff;
                new_grid[j][i] = -diff;
            }
        }
    }

    cout << 2 << endl;
    print_matrix(grid, n);
    print_matrix(new_grid, n);

    return 0;
}
