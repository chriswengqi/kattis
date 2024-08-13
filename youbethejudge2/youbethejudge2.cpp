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
    int n;
    cin >> n;
    vi visited(((1 << 2 * n) - 1) / 3 + 1, 0);
    vvi grid((1 << n), vi((1 << n), 0));

    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            if (grid[i][j] != 0 && !visited[grid[i][j]])
            {
                visited[grid[i][j]] = 1;
                int curr = grid[i][j];
                int temp_x = 1;
                int temp_y = 1;
                queue<pii> q;
                q.push({i, j});
                int ttl = 1;
                grid[i][j] = 0;
                while (q.size() > 0)
                {
                    auto [x, y] = q.front();
                    q.pop();

                    for (auto [dx, dy] : directions)
                    {
                        int xx = x + dx;
                        int yy = y + dy;
                        if (xx >= 0 && xx < (1 << n) && yy >= 0 && yy < (1 << n) && grid[xx][yy] == curr)
                        {
                            temp_x *= dx;
                            temp_y *= dy;
                            ttl++;
                            grid[xx][yy] = 0;
                            q.push({xx, yy});
                        }
                    }
                }

                if (ttl != 3 || temp_x == 1 || temp_y == 1)
                {
                    cout << 0 << endl;
                    return;
                }
            }
            else if (visited[grid[i][j]])
            {
                cout << 0 << endl;
                return;
            }
        }
    }

    cout << 1 << endl;
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