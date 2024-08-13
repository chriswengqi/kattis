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

int ans = INF;
string s;
int n;
vvi dp;

int dfs(int i, int j)
{
    if (i > j)
        return 0;
    if (i == j)
        return 2;
    if (dp[i][j] != INF)
        return dp[i][j];
    int ans = 2 * (j - i + 1);
    ans = min(ans, 2 + dfs(i, j - 1));
    for (int k = i; k < j; k++)
    {
        if (s[k] == s[j])
            ans = min(ans, dfs(i, k) + dfs(k + 1, j - 1));
    }

    dp[i][j] = ans;

    return ans;
}

void solve()
{
    getline(cin, s);
    ans = INF;
    n = s.size();
    // n--;
    dp.assign(n + 5, vi(n + 5, INF));

    cout << n + dfs(0, n - 1) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    string _;
    getline(cin, _);

    while (TC--)
    {
        solve();
    }

    return 0;
}