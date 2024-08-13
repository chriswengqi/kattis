#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        string t;
        cin >> t;

        vvi dp(s.size(), vi(t.size(), -1));

        function<int(int, int)> dfs = [&](int i, int j)
        {
            if ((i == s.size()) && (j == t.size()))
            {
                return 1;
            }
            else if ((i == s.size()) || (j == t.size()))
                return 0;
            if (s[i] != t[j] && s[i] != '*')
                return 0;
            if (dp[i][j] != -1)
                return dp[i][j];
            int ans = dfs(i + 1, j + 1);
            if (s[i] == '*')
            {
                ans |= dfs(i, j + 1);
                ans |= dfs(i + 1, j);
            }
            return dp[i][j] = ans;
        };

        if (dfs(0, 0))
            cout << t << endl;
    }

    return 0;
}