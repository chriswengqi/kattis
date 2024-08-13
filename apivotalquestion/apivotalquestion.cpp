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

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 1)
    {
        cout << n << " " << arr[0] << endl;
        return;
    }
    vi suf = arr;
    vi pref = arr;
    for (int i = 1; i < n; i++)
        pref[i] = max(arr[i], pref[i - 1]);
    for (int i = n - 2; i >= 0; i--)
        suf[i] = min(arr[i], suf[i + 1]);
    vi ans;

    for (int i = 0; i < n; i++)
    {
        if (i == 0 && arr[i] < suf[i + 1])
            ans.pb(arr[i]);
        if (i == n - 1 && arr[i] > pref[i - 1])
            ans.pb(arr[i]);
        if (i != 0 && i != n - 1 && arr[i] > pref[i - 1] && arr[i] < suf[i + 1])
            ans.pb(arr[i]);
    }

    cout << ans.size() << " ";
    for (int i = 0; i < min((int)ans.size(), 100LL); i++)
        cout << ans[i] << " ";
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