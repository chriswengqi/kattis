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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vi fibs{0, 1, 1};
    for (int i = 3; i < 1000; i++)
    {
        fibs.pb(fibs[i - 1] + fibs[i - 2]);
        if (fibs.back() >= 1e18 || fibs.back() < 0)
            break;
    }
    int n, k;
    cin >> n >> k;
    n = min(n, 89LL);

    function<char(int, int)> dfs = [&](int u, int v)
    {
        if (v == 1)
            return 'N';
        if (v == 2)
            return 'A';
        if (u > fibs[v - 2])
            return dfs(u - fibs[v - 2], v - 1);
        else
            return dfs(u, v - 2);
    };

    cout << dfs(k, n) << endl;

    return 0;
}