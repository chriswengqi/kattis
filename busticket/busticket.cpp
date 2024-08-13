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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int s, p, m, n;
    cin >> s >> p >> m >> n;
    vi arr(n), dp(n, LLINF);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dp[0] = s;
    for (int i = 1; i < n; i++)
    {
        auto it = lower_bound(arr.begin(), arr.end(), arr[i] - m + 1);
        if (it != arr.begin())
        {
            it--;
            dp[i] = min(dp[i - 1] + s, p + dp[it - arr.begin()]);
        }
        else
        {
            dp[i] = min(dp[i - 1] + s, p);
        }
    }
    // debug(dp);
    cout << dp[n - 1] << endl;

    return 0;
}