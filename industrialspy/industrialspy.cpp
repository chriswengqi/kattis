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

bool is_prime(int x)
{
    if (x < 2)
        return false;
    if (x == 2)
        return true;
    else
    {
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
                return false;
        }
    }
    return true;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    uset<int> ans;
    function<void(int, int)> dfs = [&](int curr, int bitmask)
    {
        if (is_prime(curr))
        {
            ans.insert(curr);
        }

        if (bitmask == (1 << n) - 1)
            return;
        for (int i = 0; i < n; i++)
        {
            if (!((1 << i) & bitmask))
            {
                dfs(curr * 10 + int(s[i] - '0'), bitmask | (1 << i));
            }
        }
    };
    dfs(0, 0);
    cout << ans.size() << endl;
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