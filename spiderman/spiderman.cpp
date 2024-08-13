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

vi arr, dp;
int n;
int max_peak = 1000;
string ans = "";
umap<int, int> memo;

void dfs(int ind, int curr, int peak, string s)
{
    if (ind == n)
    {
        if (curr == 0 && peak < max_peak)
        {
            ans = s;
            max_peak = peak;
        }
        return;
    }

    if (curr > dp[ind]) // too high, no way home
    {
        return;
    }

    if (!memo.count(ind * 1000 + curr) || memo[ind * 1000 + curr] > peak)
    {
        memo[ind * 1000 + curr] = peak;
    }
    else
    {
        return;
    }

    // cout << ind << " " << curr << " " << peak << endl;
    // up
    dfs(ind + 1, curr + arr[ind], max(peak, curr + arr[ind]), s + "U");

    // down
    if (arr[ind] <= curr)
        dfs(ind + 1, curr - arr[ind], max(peak, curr), s + "D");
}

void solve()
{
    cin >> n;

    arr.resize(n, 0);
    max_peak = 1000;
    ans = "";
    memo.clear();
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp = arr;
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] += dp[i + 1];
    }

    dfs(0, 0, 0, "");

    if (ans != "")
        cout << ans << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        solve();
    }

    return 0;
}