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

void solve(int n)
{
    umap<string, int> dic;
    int ctr = 0;
    vvi adj(n * 2, vi(n * 2, 0));
    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;
        if (!dic.count(s))
        {
            dic[s] = ctr;
            ctr++;
        }
        if (!dic.count(t))
        {
            dic[t] = ctr;
            ctr++;
        }
        adj[dic[s]][dic[t]] = 1;
        adj[dic[t]][dic[s]] = 1;
    }

    if (ctr % 3 != 0)
    {
        cout << "impossible" << endl;
        return;
    }

    vi dp((1 << ctr), -1);

    function<bool(int)> dfs = [&](int b)
    {
        if (b == (1 << ctr) - 1)
        {
            return true;
        }
        if (dp[b] != -1)
        {
            return (dp[b] ? true : false);
        }
        bool ans = false;
        for (int i = 0; i < ctr; i++)
        {
            if ((1 << i) & b)
                continue;
            for (int j = i + 1; j < ctr; j++)
            {
                if ((1 << j) & b)
                    continue;
                for (int k = j + 1; k < ctr; k++)
                {
                    if ((1 << k) & b)
                        continue;
                    if (adj[i][j] == 1 && adj[j][k] == 1 && adj[i][k] == 1)
                    {
                        ans |= dfs(b | (1 << i) | (1 << j) | (1 << k));
                        if (ans)
                        {
                            dp[b] = 1;
                            return true;
                        }
                    }
                }
            }
        }
        dp[b] = 0;
        return false;
    };

    cout << (dfs(0) ? "possible" : "impossible") << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n != 0)
    {
        solve(n);
        cin >> n;
    }

    return 0;
}