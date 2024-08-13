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

struct Pt
{
    int x;
    int y;
    int z;
};

void solve()
{
    int n;
    cin >> n;
    int ctr = 0;
    umap<string, int> dic;
    vector<Pt> arr;
    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        string name;
        cin >> name;
        if (!dic.count(name))
        {
            dic[name] = ctr++;
        }
        arr.pb({s, t, dic[name]});
    }

    function<int(int, int)> dist = [&](int i, int j)
    {
        return abs(arr[i].x - arr[j].x) + abs(arr[i].y - arr[j].y);
    };

    vvi dp(n + 1, vi(1 << ctr + 1, -1));

    function<int(int, int)> dfs = [&](int u, int bitmask)
    {
        if (bitmask == (1 << ctr) - 1)
        {
            return abs(arr[u].x) + abs(arr[u].y);
        }
        if (dp[u][bitmask] != -1)
            return dp[u][bitmask];
        int ans = LLINF;
        for (int i = 0; i < n; i++)
        {
            if (!(bitmask & (1 << (arr[i].z))))
            {
                ans = min(ans, dist(u, i) + dfs(i, bitmask | (1 << (arr[i].z))));
            }
        }
        return dp[u][bitmask] = ans;
    };

    int ans = LLINF;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, abs(arr[i].x) + abs(arr[i].y) + dfs(i, (1 << arr[i].z)));
    }
    cout << ans << endl;
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