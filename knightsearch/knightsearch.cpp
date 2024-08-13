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

vpii directions{{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, -1}, {2, 1}, {-2, 1}, {-2, -1}};
vector<vc> grid;
string s = "ICPCASIASG";
bool found = false;
int n;

void dfs(int i, int j, int pos)
{
    if (pos == 10)
    {
        found = true;
        return;
    }
    for (auto [dx, dy] : directions)
    {
        int x = i + dx;
        int y = j + dy;
        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == s[pos])
        {
            dfs(x, y, pos + 1);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    grid.resize(n, vc(n));
    for (int i = 0; i < n * n; i++)
    {
        cin >> grid[i / n][i % n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 'I')
            {
                dfs(i, j, 1);
            }

            if (found)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}