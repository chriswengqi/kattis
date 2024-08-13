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

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vvi grid(n, vi(n));
    vvi visited(n, vi(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    priority_queue<pair<int, pii>> pq;
    pq.push({-grid[0][0], {0, 0}});

    while (pq.size() > 0)
    {
        auto [curr, b] = pq.top();
        curr = -curr;
        auto [x, y] = b;
        pq.pop();
        if (x == n - 1 && y == n - 1)
        {
            cout << max(0LL, curr - grid[0][0]) << endl;
            return 0;
        }
        if (visited[x][y] == 0)
        {
            visited[x][y] = 1;
            for (auto [dx, dy] : directions)
            {
                if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < n)
                    pq.push({-max(curr, grid[x + dx][y + dy]), {x + dx, y + dy}});
            }
        }
    }

    return 0;
}
