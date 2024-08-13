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
    int n, k;
    cin >> n >> k;
    vvi grid(n, vi(k, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> grid[i][j];
        }
    }

    vvi dp(n, vi(k, -1));
    int ctr = 0;

    vector<uset<int>> adj(n * k, uset<int>());

    vi dx{-1, 0, 0, 1};
    vi dy{0, -1, 1, 0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int lowest = grid[i][j];
            int next_x = -1;
            int next_y = -1;

            for (int jj = 0; jj < 4; jj++)
            {
                if (i + dx[jj] >= 0 && i + dx[jj] < n && j + dy[jj] >= 0 && j + dy[jj] < k && grid[i + dx[jj]][j + dy[jj]] < lowest)
                {
                    lowest = grid[i + dx[jj]][j + dy[jj]];
                    next_x = i + dx[jj];
                    next_y = j + dy[jj];
                }
            }

            if (next_x != -1)
            {
                int curr = i * k + j;
                int nxt = next_x * k + next_y;
                adj[curr].insert(nxt);
                adj[nxt].insert(curr);
            }
        }
    }

    // for (int i = 0; i < n * k; i++)
    // {
    //     cout << i << ":" << endl;
    //     for (int a : adj[i])
    //     {
    //         cout << a << " ";
    //     }
    //     cout << endl;
    // }

    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            queue<int> q;
            if (dp[i][j] != -1)
                continue;
            q.push(i * k + j);
            while (q.size() > 0)
            {
                int x = q.front();
                q.pop();
                if (dp[x / k][x % k] != -1)
                {
                    continue;
                }
                dp[x / k][x % k] = curr;
                for (int a : adj[x])
                {
                    q.push(a);
                }
            }

            curr++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << (char)(dp[i][j] + 'a') << " ";
        }
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    for (int i = 1; i <= TC; i++)
    {
        cout << "Case #" << i << ":" << endl;
        solve();
    }

    return 0;
}