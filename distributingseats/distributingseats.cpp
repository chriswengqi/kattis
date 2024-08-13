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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, c;
    cin >> n >> r >> c;

    vi rows(r + 1, 0);
    vector<pii> arr;

    for (int i = 0; i < n; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;
        arr.pb({min(r, a + s), max(1LL, a - s)});
    }

    sort(arr.begin(), arr.end());
    map<int, int> dic;
    for (int i = 1; i <= r; i++)
    {
        dic[i] = c;
    }
    int ans = 0;
    for (auto [r, l] : arr)
    {
        if (dic.lower_bound(l) == dic.end())
            continue;
        auto &[curr, k] = *dic.lower_bound(l);
        // cout << r << " " << l << " " << curr << " " << k << endl;
        if (curr > r)
        {
            continue;
        }
        ans++;
        k--;
        if (k == 0)
        {
            dic.erase(curr);
        }
    }
    cout << ans << endl;

    return 0;
}