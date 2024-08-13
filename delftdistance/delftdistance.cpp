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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    cin >> h >> w;
    vs grid(h);
    for (int i = 0; i < h; i++)
        cin >> grid[i];

    vvd dp(2 * h + 1, vd(2 * w + 1, 0));

    for (int i = 0; i < 2 * h + 1; i++)
        dp[i][0] = 5.0 * (double)i;

    for (int i = 0; i < 2 * w + 1; i++)
        dp[0][i] = 5.0 * (double)i;

    for (int i = 1; i < 2 * h + 1; i++)
    {
        for (int j = 1; j < 2 * w + 1; j++)
        {
            if (i & 1 && j & 1)
            {
            }
            else
            {
                if (i & 1 && !(j & 1) && grid[i / 2][j / 2 - 1] == 'O')
                {
                    // cout << i << ' ' << j << endl;
                    dp[i][j] = min(dp[i - 1][j] + 5.0, dp[i - 1][j - 1] + 5.0 * M_PI / 2.0);
                    // cout << dp[i - 1][j - 1] << " " << dp[i][j] << endl;
                }
                else if (!(i & 1) && (j & 1) && grid[i / 2 - 1][j / 2] == 'O')
                {
                    dp[i][j] = min(dp[i][j - 1] + 5.0, dp[i - 1][j - 1] + 5.0 * M_PI / 2.0);
                }
                else if (i & 1 && !(j & 1))
                {
                    dp[i][j] = dp[i - 1][j] + 5.0;
                }
                else if (!(i & 1) && (j & 1))
                {
                    dp[i][j] = dp[i][j - 1] + 5.0;
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j] + 5, dp[i][j - 1] + 5);
                }
            }

            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    // for (int i = 0; i < 2 * h + 1; i++)
    // {
    //     for (int j = 0; j < 2 * w + 1; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << fixed << setprecision(10) << dp[2 * h][2 * w] << endl;

    return 0;
}