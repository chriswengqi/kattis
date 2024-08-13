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

vi arr;
vector<vvi> dp;
int n;
int ttl = 0;
int op = 0;

bool dfs(int curr, int cnt, int sum)
{

    if (cnt > (n + 1) / 2)
        return false;
    if (sum * 2 > ttl)
        return false;
    if (curr == n)
    {
        op = max(sum, op);
        return true;
    }

    if (dp[curr][cnt][sum] != -1)
    {
        return dp[curr][cnt][sum] == 1;
    }

    bool ans = dfs(curr + 1, cnt + 1, sum + arr[curr]) || dfs(curr + 1, cnt, sum);
    // take or don't take
    for (int i = curr; i < n; i++)
    {
        ans |= dfs(i + 1, cnt + 1, sum + arr[i]);
    }

    op = max(sum, op);

    return dp[curr][cnt][sum] = ans;
}

void solve()
{
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ttl += arr[i];
    }
    dp.assign(n + 5, vvi(n / 2 + 5, vi(ttl / 2 + 5, -1)));

    dfs(0, 0, 0);

    cout << op << " " << ttl - op << endl;
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