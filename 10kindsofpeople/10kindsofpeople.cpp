#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair

int R, C;
vvi grid;
vvi visited;
vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int val, int curr, int i, int j)
{
    deque<pii> d;
    d.pb({i, j});

    while (d.size() > 0)
    {
        pii x = d.front();
        d.pop_front();
        visited[x.first][x.second] = 1;
        grid[x.first][x.second] = curr;

        for (auto dir : directions)
        {
            int dx = x.first + dir.first;
            int dy = x.second + dir.second;
            if (dx >= 0 && dx < R && dy >= 0 && dy < C)
            {
                if (visited[dx][dy] == 0 && grid[dx][dy] == val)
                {
                    d.pb({dx, dy});
                    visited[dx][dy] = 1;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    grid.resize(R, vi(C));
    visited.resize(R, vi(C, 0));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char s;
            cin >> s;
            grid[i][j] = s - '0';
        }
    }

    int a = 2;
    int b = -1;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int curr;

            if (grid[i][j] == 0 || grid[i][j] == 1)
            {
                curr = grid[i][j] == 0 ? a++ : b--;
                bfs(grid[i][j], curr, i, j);
            }
        }
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int xi, yi, xj, yj;
        cin >> xi >> yi >> xj >> yj;

        if (grid[xi - 1][yi - 1] > 0 && grid[xi - 1][yi - 1] == grid[xj - 1][yj - 1])
            cout << "binary" << endl;
        else if (grid[xi - 1][yi - 1] < 0 && grid[xi - 1][yi - 1] == grid[xj - 1][yj - 1])
            cout << "decimal" << endl;
        else
            cout << "neither" << endl;
    }
    return 0;
}