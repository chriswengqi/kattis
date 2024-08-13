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

vector<vpii> prices;
vvi dp;
vi postal_prices;
int ans = 1e9;
int n, m;

int dfs(int curr, int bitmask)
{
    if (curr == n + 1)
    {
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            if ((1 << i) & bitmask)
                ans += postal_prices[i];
        }
        return ans;
    }

    if (dp[bitmask][curr] != -1)
    {
        return dp[bitmask][curr];
    }

    int ans = LLINF;

    for (auto [k, v] : prices[curr])
    {
        ans = min(ans, v + dfs(curr + 1, bitmask | (1 << k)));
    }

    return dp[bitmask][curr] = ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    prices.resize(n + 1);
    dp.resize(1LL << m, vi(n + 1, -1));
    postal_prices.resize(m, 0);

    for (int i = 0; i < m; i++)
    {
        int s, p;
        cin >> s >> p;
        postal_prices[i] = p;
        for (int j = 0; j < s; j++)
        {
            int book, price;
            cin >> book >> price;
            prices[book].pb({i, price});
        }
    }

    cout << dfs(1, 0) << endl;

    return 0;
}