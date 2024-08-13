#include <bits/stdc++.h>

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
#define sz(x) (int)x.size()
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
    int n;
    cin >> n;
    vs arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    umap<char, int> dic;
    dic['U'] = 0;
    dic['H'] = 1;
    dic['N'] = 2;
    dic['V'] = 3;

    vector<vvi> dp(4, vvi(4, vi(n + 1, -1)));

    function<int(int, int, int)> dfs = [&](int l, int r, int curr)
    {
        if (curr == n)
            return 0LL;
        if (dp[l][r][curr] != -1)
            return dp[l][r][curr];
        if (arr[curr].size() == 1)
        {
            // dont move
            if (dic[arr[curr][0]] == l || dic[arr[curr][0]] == r)
            {
                dp[l][r][curr] = dfs(l, r, curr + 1);
            }
            else
            {
                dp[l][r][curr] = 1 + min(dfs(dic[arr[curr][0]], r, curr + 1), dfs(l, dic[arr[curr][0]], curr + 1));
            }
        }
        else
        {
            int n1 = dic[arr[curr][0]];
            int n2 = dic[arr[curr][1]];
            if ((n1 == l && n2 == r) || (n1 == r && n2 == l))
            {
                dp[l][r][curr] = dfs(l, r, curr + 1);
            }
            else if (n1 == l)
            {
                dp[l][r][curr] = 1 + dfs(l, n2, curr + 1);
            }
            else if (n1 == r)
            {
                dp[l][r][curr] = 1 + dfs(n2, r, curr + 1);
            }
            else if (n2 == l)
            {
                dp[l][r][curr] = 1 + dfs(l, n1, curr + 1);
            }
            else if (n2 == r)
            {
                dp[l][r][curr] = 1 + dfs(n1, r, curr + 1);
            }
            else
            {
                dp[l][r][curr] = 2 + dfs(n1, n2, curr + 1);
            }
        }
        return dp[l][r][curr];
    };

    cout << dfs(3, 1, 0) << endl;
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