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

void debug(string s)
{
    cout << s << endl;
}

int n, d, m;

vpii directions;

vector<vvi> moles;
vector<vvi> dp;

int w(int x, int y, int i, int j, int t)
{
    int gcd = __gcd(abs(i), abs(j));
    int ans = (x >= 0 && x < n && y >= 0 && y < n) ? moles[x][y][t] : 0;
    for (int k = 0; k < gcd; k++)
    {
        if (x - i + k * i / gcd >= 0 && x - i + k * i / gcd < n && y - j + k * j / gcd >= 0 && y - j + k * j / gcd < n)
            ans += moles[x - i + k * i / gcd][y - j + k * j / gcd][t];
    }

    return ans;
}

int p(int x, int y, int t)
{
    if (t == 0)
        return 0;
    if (x < -d || x >= n + d || y < -d || y >= n + d)
    {
        return 0;
    }
    // offset
    if (dp[x + d][y + d][t] != -1)
    {
        return dp[x + d][y + d][t];
    }
    // cout << x << " " << y << " " << t << endl;
    int ans = 0;
    for (auto [dx, dy] : directions)
    {
        ans = max(ans, p(x - dx, y - dy, t - 1) + w(x, y, dx, dy, t));
    }

    dp[x + d][y + d][t] = ans;

    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d >> m;
    while (n != 0 || d != 0 || m != 0)
    {
        moles.assign(n, vvi(n, vi(11, 0)));
        dp.assign(n + 2 * d, vvi(n + 2 * d, vi(11, -1)));
        directions.clear();

        for (int i = -d; i <= d; i++)
        {
            for (int j = -d; j <= d; j++)
            {
                if (i * i + j * j <= d * d)
                {
                    directions.pb({i, j});
                }
            }
        }

        int max_t = 0;
        for (int i = 0; i < m; i++)
        {
            int x, y, t;
            cin >> x >> y >> t;
            max_t = max(t, max_t);
            moles[x][y][t] = 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans = max(p(i, j, max_t), ans);
            }
        }

        cout << ans << endl;

        cin >> n >> d >> m;
    }

    return 0;
}