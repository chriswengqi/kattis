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
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
#define debug1(a)                           \
    for (int i = 0; i <= a.size() - 1; i++) \
    cout << a[i] << (i == a.size() - 1 ? '\n' : ' ')
#define debug2(a)                                  \
    for (int i = 0; i <= a.size() - 1; i++)        \
        for (int j = 0; j <= a[0].size() - 1; j++) \
    cout << a[i][j] << (j == a[0].size() - 1 ? '\n' : ' ')

vpii directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
struct State
{
    int x;
    int y;
    int bitmask;
    int direction;
    string s;
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vs grid(8);
    int x;
    int y;
    int ss = 0; // keeps track of the ice only;
    for (int i = 0; i < 8; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < 8; j++)
        {
            if (grid[i][j] == 'T')
            {
                x = i;
                y = j;
            }
            if (grid[i][j] == 'I' || grid[i][j] == 'C')
            {
                ss |= (1LL << (i * 8 + j));
            }
        }
    }

    vector<vvi> visited(8, vvi(8, vi(4, 0)));

    queue<State> q;
    q.push({x, y, ss, 0, ""});

    while (q.size() > 0)
    {
        State curr = q.front();
        q.pop();

        if (grid[curr.x][curr.y] == 'D')
        {
            cout << curr.s << endl;
            return 0;
        }

        int new_x = curr.x + directions[curr.direction].first;
        int new_y = curr.y + directions[curr.direction].second;
        if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8 && !((1LL << (new_x * 8 + new_y) & curr.bitmask)))
        {
            q.push({new_x, new_y, curr.bitmask, curr.direction, curr.s + "F"});
        }

        if (visited[curr.x][curr.y][curr.direction])
        {
            continue;
        }

        visited[curr.x][curr.y][curr.direction] = 1;

        // turn right

        q.push({curr.x, curr.y, curr.bitmask, (curr.direction + 1) % 4, curr.s + "R"});

        // turn left

        q.push({curr.x, curr.y, curr.bitmask, (curr.direction + 3) % 4, curr.s + "L"});

        // fire in direction
        for (int i = 1; i < 8; i++)
        {
            int curr_x = curr.x + directions[curr.direction].first * i;
            int curr_y = curr.y + directions[curr.direction].second * i;
            if (curr_x < 0 || curr_x >= 8 || curr_y < 0 || curr_y >= 8)
            {
                break;
            }
            if (grid[curr_x][curr_y] == 'C')
                break;
            if (grid[curr_x][curr_y] == 'I')
            {
                int new_bm = curr.bitmask ^ (1LL << (curr_x * 8 + curr_y));
                q.push({curr.x, curr.y, new_bm, curr.direction, curr.s + "X"});
                break;
            }
        }
    }

    cout << "no solution" << endl;
    return 0;
}