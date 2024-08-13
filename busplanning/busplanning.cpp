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
    int n, m, k;
    cin >> n >> m >> k;
    umap<string, int> dic;
    vs arr;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (!dic.count(s))
        {
            dic[s] = arr.size();
            arr.pb(s);
        }
    }
    vvi fight(n, vi(n, 0));
    for (int i = 0; i < m; i++)
    {
        string s, t;
        cin >> s >> t;
        fight[dic[s]][dic[t]] = fight[dic[t]][dic[s]] = 1;
    }

    vi stack;
    vi ans;

    function<void(int)> dfs = [&](int u)
    {
        if (u == n)
        {
            if (ans.size() == 0 || stack.size() < ans.size())
            {
                ans = stack;
            }
            return;
        }
        if (ans.size() > 0 && stack.size() >= ans.size())
        {
            return;
        }
        for (int j = 0; j < stack.size(); j++)
        {
            bool can = true;
            for (int i = 0; i < n && can; i++)
            {
                if (i != u && ((1 << i) & stack[j]) && fight[i][u] == 1)
                {
                    can = false;
                }
            }
            if (can && __builtin_popcount(stack[j]) < k)
            {
                stack[j] ^= (1 << u);
                dfs(u + 1);
                stack[j] ^= (1 << u);
            }
        }
        stack.pb((1 << u));
        dfs(u + 1);
        stack.pop_back();
    };

    dfs(0);

    cout << ans.size() << endl;
    for (int a : ans)
    {
        assert(__builtin_popcount(a) <= k);
        for (int i = 0; i < n; i++)
        {
            if ((1 << i) & a)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
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