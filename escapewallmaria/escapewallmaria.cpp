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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, m;
    cin >> t >> n >> m;
    vs grid(n);
    int start_x, start_y;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'S')
            {
                start_x = i;
                start_y = j;
            }
        }
    }

    queue<pair<int, pii>> q;
    q.push({0, {start_x, start_y}});
    vi dx{1, -1, 0, 0};
    vi dy{0, 0, 1, -1};
    while (q.size() > 0)
    {
        auto [time, coords] = q.front();
        int x = coords.first;
        int y = coords.second;
        q.pop();
        // cout << time << " " << x << " " << y << endl;
        if (time > t)
        {
            cout << "NOT POSSIBLE" << endl;
            return 0;
        }
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
        {
            cout << time << endl;
            return 0;
        }
        // U, D, L, R
        for (int i = 0; i < 4; i++)
        {
            if (grid[x + dx[i]][y + dy[i]] == '0')
            {
                q.push({time + 1, {x + dx[i], y + dy[i]}});
            }
            if (i == 0 && grid[x + dx[i]][y + dy[i]] == 'U')
            {
                q.push({time + 1, {x + dx[i], y + dy[i]}});
            }
            if (i == 1 && grid[x + dx[i]][y + dy[i]] == 'D')
            {
                q.push({time + 1, {x + dx[i], y + dy[i]}});
            }
            if (i == 2 && grid[x + dx[i]][y + dy[i]] == 'L')
            {
                q.push({time + 1, {x + dx[i], y + dy[i]}});
            }
            if (i == 3 && grid[x + dx[i]][y + dy[i]] == 'R')
            {
                q.push({time + 1, {x + dx[i], y + dy[i]}});
            }
        }

        grid[x][y] = '1';
    }

    cout << "NOT POSSIBLE" << endl;

    return 0;
}