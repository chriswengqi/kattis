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

void debug(vpii &arr)
{
    for (auto [k, v] : arr)
    {
        cout << k << " " << v << endl;
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
set<int> ans;
vvi grid{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};

void dfs(int ii, int jj, int curr)
{
    if (curr > 200)
        return;
    ans.insert(curr);

    for (int i = ii; i < 4; i++)
    {
        for (int j = jj; j < 3; j++)
        {
            if (grid[i][j] != -1)
            {
                dfs(i, j, curr * 10 + grid[i][j]);
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dfs(i, j, grid[i][j]);
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        auto lb = ans.lower_bound(s);
        if (lb == ans.begin())
        {
            cout << *lb << endl;
        }
        else
        {
            int up = *lb;
            lb--;
            int down = *lb;
            if (up - s < s - down)
                cout << up << endl;
            else
                cout << down << endl;
        }
    }

    // for (int a : ans)
    // {
    //     cout << a << " ";
    // }
    // cout << endl;
    return 0;
}