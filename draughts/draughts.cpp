#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
typedef tuple<int, int, int> iii;

#define pb push_back
#define em emplace
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define INF 1e9
#define LLINF 4e18
#define umap unordered_map
#define uset unordered_set

vpii directions{{1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

void debug(int a)
{
    cout << a << endl;
}

void debug(vi &arr)
{
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}

void debug(vvi &grid)
{
    for (vi row : grid)
    {
        for (int a : row)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}

void debug(vpii &arr)
{
    for (auto [k, v] : arr)
    {
        cout << k << " " << v << endl;
    }
}

void debug(string s)
{
    cout << s << endl;
}

int ans = 0;

void dfs(vs old_grid, int curr, int x, int y)
{
    // for (string s : old_grid)
    // {
    //     cout << s << endl;
    // }
    // cout << endl;
    for (auto [dx, dy] : directions)
    {
        if (x + dx >= 0 && x + dx < 10 && y + dy >= 0 && y + dy < 10 && old_grid[x + dx][y + dy] == 'B')
        {
            if (x + 2 * dx >= 0 && x + 2 * dx < 10 && y + 2 * dy >= 0 && y + 2 * dy < 10 && old_grid[x + 2 * dx][y + 2 * dy] == '#')
            {
                vs grid(10);
                for (int i = 0; i < 10; i++)
                {
                    string new_s = old_grid[i];
                    grid[i] = new_s;
                }
                grid[x][y] = '#';
                grid[x + dx][y + dy] = '#';
                grid[x + 2 * dx][y + 2 * dy] = 'W';
                ans = max(curr + 1, ans);
                dfs(grid, curr + 1, x + 2 * dx, y + 2 * dy);
            }
        }
    }
}
void solve()
{
    int r = 0, c = 0;
    ans = 0;
    vpii whites;
    vs grid(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> grid[i];

        for (int j = 0; j < 10; j++)
        {
            if (grid[i][j] == 'W')
            {
                whites.pb({i, j});
            }
        }
    }
    for (auto [r, c] : whites)
        dfs(grid, 0, r, c);

    cout << ans << endl;
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