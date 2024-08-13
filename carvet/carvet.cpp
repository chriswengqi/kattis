#include <bits/stdc++.h>

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
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define INF 1e9
#define LLINF 4e18
#define umap unordered_map
#define uset unordered_set
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
#define debug1(a)                           \
    for (int i = 0; i <= a.size() - 1; i++) \
    cout << a[i] << (i == a.size() - 1 ? '\n' : ' ')
#define debug2(a)                                  \
    for (int i = 0; i <= a.size() - 1; i++)        \
        for (int j = 0; j <= a[0].size() - 1; j++) \
    cout << a[i][j] << (j == a[0].size() - 1 ? '\n' : ' ')

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve()
{
    int n, m;
    cin >> n >> m;
    vvi grid(n, vi(m));
    vpii moves;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == -1)
            {
                moves.pb({i, j});
            }
        }
    }
    int p, q;
    cin >> p >> q;
    p--;
    q--;
    vi ans;
    vi stack;
    function<void(int, int, int)> dfs = [&](int i, int j, int prev)
    {
        if (i == p && j == q)
        {
            if (ans.size() == 0 || stack.size() < ans.size())
            {
                ans = stack;
            }
            else if (ans.size() == stack.size())
            {
                for (int k = 0; k < ans.size(); k++)
                {
                    if (stack[k] < ans.size())
                    {
                        ans = stack;
                        break;
                    }
                }
            }
            return;
        }

        for (auto [dx, dy] : directions)
        {
            if (i + dx * 2 >= 0 && i + dx * 2 < n && j + dy * 2 >= 0 && j + dy * 2 < m)
            {
                if (grid[i + dx][j + dy] == grid[i + 2 * dx][j + 2 * dy] && grid[i + dx][j + dy] != prev)
                {
                    stack.pb(grid[i + dx][j + dy]);
                    swap(grid[i][j], grid[i + 2 * dx][j + 2 * dy]);
                    dfs(i + 2 * dx, j + 2 * dy, grid[i + dx][j + dy]);
                    stack.pop_back();
                    swap(grid[i][j], grid[i + 2 * dx][j + 2 * dy]);
                }
            }
        }
    };

    for (auto [x, y] : moves)
    {
        dfs(x, y, -3);
    }

    if (ans.size() == 0)
    {
        cout << "impossible" << endl;
    }
    else
    {
        for (int a : ans)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    TC = 1;

    while (TC--)
    {
        solve();
    }

    return 0;
}