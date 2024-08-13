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
    int n, a, b, c, d, x0, y0, m;
    cin >> n >> a >> b >> c >> d >> x0 >> y0 >> m;

    vpii curr;
    vi res(9, 0);
    int prev_x = x0;
    int prev_y = y0;
    res[(x0 % 3) * 3 + (y0 % 3)]++;
    for (int i = 1; i < n; i++)
    {
        int x = (a * prev_x + b) % m;
        int y = (c * prev_y + d) % m;
        res[(x % 3) * 3 + (y % 3)]++;
        prev_x = x;
        prev_y = y;
    }
    int ans = 0;
    for (int i = 0; i < 9; i++)
    {
        if (res[i] >= 3)
            ans += (res[i] * (res[i] - 1) * (res[i] - 2)) / 6;
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            int x = (i / 3) + (j / 3);
            int y = (i % 3) + (j % 3);
            int comp_x = (3 - x % 3) % 3;
            int comp_y = (3 - y % 3) % 3;
            if (comp_x * 3 + comp_y > j)
                ans += res[i] * res[j] * res[comp_x * 3 + comp_y];
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    int ctr = 1;
    while (TC--)
    {
        cout << "Case #" << ctr << ": ";
        solve();
        ctr++;
    }

    return 0;
}