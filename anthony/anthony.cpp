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
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
#define debug1(a)                           \
    for (int i = 0; i <= a.size() - 1; i++) \
    cout << a[i] << (i == a.size() - 1 ? '\n' : ' ')
#define debug2(a)                                  \
    for (int i = 0; i <= a.size() - 1; i++)        \
        for (int j = 0; j <= a[0].size() - 1; j++) \
    cout << a[i][j] << (j == a[0].size() - 1 ? '\n' : ' ')

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve()
{
    int n, m;
    cin >> n >> m;
    vd arr(n + m);
    vvd dp(n + m + 5, vd(m + 5, -1));
    for (int i = 0; i < n + m - 1; i++)
    {
        cin >> arr[i];
    }

    function<double(int, int)> dfs = [&](int curr, int pts)
    {
        if (pts == m)
            return 1.0;
        else if (curr == n + m - 1)
            return 0.0;
        else if (curr - pts == n)
            return 0.0;

        if (dp[curr][pts] != -1)
        {
            return dp[curr][pts];
        }
        return dp[curr][pts] = arr[curr] * dfs(curr + 1, pts + 1) + (1.0 - arr[curr]) * dfs(curr + 1, pts);
    };

    cout << fixed << setprecision(10) << dfs(0, 0) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    TC = 1;

    while (TC--)
    {
        solve();
    }

    return 0;
}