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

void debug(vd &arr)
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

vector<vector<pair<int, double>>> adj;
vd dp;
vd dp_prob;
double dfs(int u)
{
    if (dp[u] != -1)
        return dp[u];
    double curr = 0;
    for (auto [k, v] : adj[u])
    {
        curr += dfs(k) * v;
    }
    dp[u] = curr;
    return dp[u];
}

double dfs_prob(int u)
{
    if (dp_prob[u] != -1)
        return dp_prob[u];
    double curr = 0;
    for (auto [k, v] : adj[u])
    {
        curr += dfs_prob(k) * v;
    }
    dp_prob[u] = curr;
    return dp_prob[u];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    dp.resize(n + m, -1);
    adj.resize(n + m, vector<pair<int, double>>());
    dp_prob.resize(n + m, -1);

    for (int i = 0; i < n; i++)
    {
        cin >> dp[i];
        dp_prob[i] = 1;
    }

    vi incoming(n + m, 0);

    for (int i = n; i < n + m; i++)
    {
        double p1, p2;
        int l, r;
        cin >> p1 >> p2 >> l >> r;
        l--, r--;
        adj[i].pb({l, p1});
        adj[i].pb({r, p2});
        incoming[l]++;
        incoming[r]++;
    }

    for (int i = 0; i < n + m; i++)
    {
        if (!incoming[i])
        {
            dfs(i);
            dfs_prob(i);
        }
    }
    double ans = 0;
    for (int i = 0; i < n + m; i++)
    {
        if (!incoming[i])
        {
            ans = max(ans, dp[i] / dp_prob[i]);
        }
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}