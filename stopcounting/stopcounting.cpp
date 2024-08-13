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
    vi arr(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vi pref = arr;
    vi pref_cnt(n + 2, 0);
    vi suf = arr;

    for (int i = n; i >= 0; i--)
    {
        suf[i] += suf[i + 1];
    }
    for (int i = 1; i <= n + 1; i++)
    {
        pref[i] += pref[i - 1];
    }
    vd suf_avg(n + 2, 0);
    vi suf_best = suf;
    vi suf_cnt(n + 2, 0);
    for (int i = n; i >= 0; i--)
    {
        suf_avg[i] = max(suf_avg[i + 1], (double)suf[i] / (double)(n + 1 - i));
    }
    // debug1(suf_avg);
    double prev = 0;
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        prev = max(prev, (double)pref[i] / (double)i);
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