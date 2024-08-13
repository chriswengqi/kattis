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

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ordered_set o;
    ordered_set p;

    int n;
    cin >> n;
    vi arr(n);
    set<int> left;
    set<int> right;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vi lb(n, 0);
    vi rb(n, 0);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i] * 2;
        int rank = o.order_of_key(curr);
        lb[i] = o.size() - rank;
        o.insert(arr[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = (arr[i] / 2) + 1;
        int rank = p.order_of_key(curr);
        rb[i] = rank;
        p.insert(arr[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += lb[i] * rb[i];
    }
    cout << ans << endl;

    return 0;
}