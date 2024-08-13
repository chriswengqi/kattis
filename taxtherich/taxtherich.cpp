#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
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

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi arr(n);
    ordered_set tree;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll total = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
        ll mean = (ll)(total + i) / (i + 1); // round up if decimal
        tree.insert(arr[i]);
        // cout << mean << " " << tree.order_of_key(mean) << endl;
        if (tree.order_of_key(mean) > (i + 1) / 2)
        {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}