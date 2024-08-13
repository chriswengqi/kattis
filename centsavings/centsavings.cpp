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
vi suf;
int n, k;

vvi dp;

int dfs(int curr, int d)
{
    if (dp[curr][d] != LLINF)
        return dp[curr][d];
    int op = (suf[curr] % 10 < 5 ? (suf[curr] / 10) * 10 : ((suf[curr] / 10) + 1) * 10);

    for (int i = curr; i < n - 1; i++) // position d after i
    {
        int tot = suf[curr] - suf[i + 1];
        if (tot % 10 < 5)
            tot = (tot / 10) * 10;
        else
            tot = ((tot / 10) + 1) * 10;
        if (d < k)
            op = min(op, tot + dfs(i + 1, d + 1));
    }

    return dp[curr][d] = op;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    arr.resize(n, 0);
    dp.resize(n + 1, vi(k + 1, LLINF));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    suf = arr;

    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] += suf[i + 1];
    }

    cout << dfs(0, 0) << endl;

    return 0;
}