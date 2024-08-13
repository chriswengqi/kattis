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

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

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

void solve()
{
    int n;
    cin >> n;
    vvi grid(n, vi(n, 2));
    debug(grid);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vvi grid1(n + 1, vi(4, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> grid1[i][j];
        }
    }
    vvi grid2(n + 1, vi(4, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> grid2[i][j];
        }
    }

    vvi visited(n + 1, vi(n + 1, 0));

    queue<pair<int, int>> q;
    q.push({1, 1}); // curr room

    while (q.size() > 0)
    {
        auto [x, y] = q.front();
        // cout << x << " " << y << endl;
        q.pop();
        if ((x == n && y != n))
        {
            cout << "No" << endl;
            return 0;
        }
        if (visited[x][y])
            continue;
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int new_x = grid1[x][i];
            int new_y = grid2[y][i];
            q.push({new_x, new_y});
        }
    }

    for (int i = 0; i <= n; i++)
    {
        if (visited[n][i])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "Impossible" << endl;

    return 0;
}