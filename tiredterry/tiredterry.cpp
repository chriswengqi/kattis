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

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p, d;
    cin >> n >> p >> d;
    string s;
    cin >> s;
    vi dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'Z')
        {
            dp[i] = dp[(i + n - 1) % n] + 1;
        }
        else
        {
            dp[i] = dp[(i + n - 1) % n];
        }
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int total = 0;
        if (i - p < 0)
        {
            total = dp[i] + (dp.back() - dp[(i - p + n) % n]);
        }
        else
        {
            total = dp[i] - dp[i - p];
        }
        if (total < d)
            ans++;
    }
    cout << ans << endl;

    return 0;
}