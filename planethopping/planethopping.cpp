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

void debug(string s)
{
    cout << s << endl;
}

vvi grid;

int ans = 0;

vector<vvi> memo;

vi dx{1, -1, 0, 0};
vi dy{0, 0, 1, -1};
int n;
void dfs(int i, int j, int total, int fuel)
{
    ans = max(total, ans);

    if (fuel == 0)
    {
        return;
    }

    if (memo[i][j][fuel] == -1 || memo[i][j][fuel] < total)
    {
        memo[i][j][fuel] = total;
    }
    else
    {
        return;
    }

    // cout << i << " " << j << " " << total << " " << fuel << endl;

    for (int x = 0; x < 4; x++)
    {
        if (i + dx[x] >= 0 && i + dx[x] < n && j + dy[x] >= 0 && j + dy[x] < n && grid[i + dx[x]][j + dy[x]] > grid[i][j])
        {
            dfs(i + dx[x], j + dy[x], total + grid[i + dx[x]][j + dy[x]], fuel - 1);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> n >> k;
    memo.resize(n, vvi(n, vi(k + 2, -1)));
    grid.resize(n, vi(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        dfs(i, 0, grid[i][0], k);
        dfs(i, n - 1, grid[i][n - 1], k);
    }

    for (int i = 1; i < n - 1; i++)
    {
        dfs(0, i, grid[0][i], k);
        dfs(n - 1, i, grid[n - 1][i], k);
    }

    cout << ans << endl;

    return 0;
}