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

void debug(string s)
{
    cout << s << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while (cin >> n >> m)
    {
        vi vals;
        vi weights;
        for (int i = 0; i < m; i++)
        {
            int s, t;
            cin >> s >> t;
            vals.pb(s);
            weights.pb(t);
        }
        vi stack;
        int ans = 0;
        vi res;
        vvi dp(m + 1, vi(n + 1, -1));
        function<int(int, int, int)> dfs = [&](int i, int w, int ttl)
        {
            if (i == m)
            {
                if (ttl > ans)
                {
                    ans = ttl;
                    res = stack;
                }
                return 0LL;
            }

            if (dp[i][w] != -1)
            {
                return dp[i][w];
            }

            int ans = dfs(i + 1, w, ttl);
            if (w >= weights[i])
            {
                stack.push_back(i);
                int curr = vals[i] + dfs(i + 1, w - weights[i], ttl + vals[i]);
                stack.pop_back();
                ans = max(ans, curr);
            }
            return dp[i][w] = ans;
        };

        dfs(0, n, 0);
        cout << res.size() << endl;
        for (int a : res)
        {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}