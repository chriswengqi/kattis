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
    vector<tuple<int, int, int>> directions{{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
    int l, r, c;
    cin >> l >> r >> c;
    vector<vs> grid(l, vs(r));
    vector<vvi> visited(l, vvi(r, vi(c, 0)));
    tuple<int, int, int> start;
    string _;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin >> grid[i][j];

            for (int k = 0; k < c; k++)
            {
                if (grid[i][j][k] == 'S')
                {
                    start = {i, j, k};
                }
            }
        }
    }

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin >> grid[i][j];

            cout << grid[i][j] << endl;
        }
    }

    deque<pair<int, tuple<int, int, int>>> dq;

    dq.push_back({0, start});

    while (dq.size() > 0)
    {
        int curr = dq.front().first;
        auto [x, y, z] = dq.front().second;

        for (auto [i, j, k] : directions)
        {
            if (x + i >= 0 && x + i < l && y + j >= 0 && y + j < r & z + k >= 0 && z + k < c && grid[x + i][y + j][z + k] == 'E')
            {
                cout << curr + 1 << endl;
                return 0;
            }
            if (x + i >= 0 && x + i < l && y + j >= 0 && y + j < r & z + k >= 0 && z + k < c && grid[x + i][y + j][z + k] == '.' && visited[x + i][y + j][z + k] == 0)
            {
                dq.push_back({curr + 1, {x + i, y + j, z + k}});
                visited[x + i][y + j][z + k] = 1;
            }
        }
    }

    return 0;
}
