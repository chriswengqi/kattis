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

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void debug(int a)
{
    cout << a << endl;
}

void debug(vi &arr)
{
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}

void debug(vvi &grid)
{
    for (vi row : grid)
    {
        for (int a : row)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}

void debug(string s)
{
    cout << s << endl;
}

void solve()
{
    int n;
    cin >> n;
    vi p(n);
    vi pts(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> pts[i];
    vvi dp(n, vi(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = i + p[i];
        int maxx = 0;
        int minn = 0;
        while (curr < n)
        {
            maxx = max(dp[curr][1], maxx);
            minn = min(dp[curr][0], minn);
            curr += p[i];
        }

        dp[i][0] = pts[i] + maxx;
        dp[i][1] = pts[i] + minn;
    }

    // debug(dp);
    for (int i = 0; i < n; i++)
    {
        cout << dp[i][0] << " ";
    }
    cout << endl;
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