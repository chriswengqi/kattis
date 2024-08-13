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

    int n, k;
    cin >> n >> k;

    vector<vpii> numbers(k + 1, vpii());
    priority_queue<tuple<int, int, pii>> pq; // {-distance, curr, coords}
    vvi dp(n, vi(n, 1e18));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int s;
            cin >> s;
            numbers[s].pb(mp(i, j));
            if (s == 1)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 2; i <= k; i++)
    {
        vi rows(n, 1e18);
        vi cols(n, 1e18);
        for (auto [x, y] : numbers[i - 1])
        {
            rows[x] = min(rows[x], dp[x][y]);
            cols[y] = min(cols[y], dp[x][y]);
        }

        for (auto [x, y] : numbers[i])
        {
            for (int prev_x = 0; prev_x < n; prev_x++)
            {
                dp[x][y] = min(dp[x][y], rows[prev_x] + (prev_x - x) * (prev_x - x));
            }
            for (int prev_y = 0; prev_y < n; prev_y++)
            {
                dp[x][y] = min(dp[x][y], cols[prev_y] + (prev_y - y) * (prev_y - y));
            }
        }
    }
    int ans = 1e18;
    for (auto [x, y] : numbers[k])
    {
        ans = min(ans, dp[x][y]);
    }

    cout << (ans == 1e18 ? -1 : ans) << endl;
    return 0;
}