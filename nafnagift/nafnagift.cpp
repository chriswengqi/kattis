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
    string s, t;
    cin >> s >> t;

    vvi dp(s.size() + 5, vi(t.size() + 5, -1));
    vvi px(s.size() + 5, vi(t.size() + 5, -1));
    vvi py(s.size() + 5, vi(t.size() + 5, -1));

    function<int(int, int)> dfs = [&](int i, int j)
    {
        if (i == s.size() && j == t.size())
        {
            return 0LL;
        }
        else if (i == s.size())
        {
            px[i][j] = i;
            py[i][j] = j + 1;
            return 1 + dfs(i, j + 1);
        }
        else if (j == t.size())
        {
            px[i][j] = i + 1;
            py[i][j] = j;
            return 1 + dfs(i + 1, j);
        }
        else
        {
            if (dp[i][j] != -1)
            {
                return dp[i][j];
            }
            int ans = 1 + dfs(i + 1, j);
            px[i][j] = i + 1;
            py[i][j] = j;

            int jj = dfs(i, j + 1);
            if (1 + jj < ans)
            {
                ans = min(ans, 1 + jj);
                px[i][j] = i;
                px[i][j] = j + 1;
            }
            if (s[i] == t[j])
            {
                int jj = dfs(i + 1, j + 1);
                if (1 + jj < ans)
                {
                    ans = jj + 1;
                    px[i][j] = i + 1;
                    py[i][j] = j + 1;
                }
            }
            return dp[i][j] = ans;
        }
    };

    dfs(0, 0);
    int curr_x = 0;
    int curr_y = 0;
    debug2(px);
    cout << endl;
    debug2(py);
    while (curr_x < s.size() || curr_y < t.size())
    {
        int new_x = px[curr_x][curr_y];
        int new_y = py[curr_x][curr_y];
        if (new_x == curr_x + 1 && new_y == curr_y + 1)
        {
            cout << s[curr_x];
        }
        else if (new_x == curr_x + 1)
        {
            cout << s[curr_x];
        }
        else if (new_y == curr_y + 1)
        {
            cout << t[curr_y];
        }
        else
        {
            assert(false);
        }
        curr_x = new_x;
        curr_y = new_y;
    }
    cout << endl;
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