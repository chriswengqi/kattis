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

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi ans;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        vi arr(k);
        for (int j = 0; j < k; j++)
            cin >> arr[j];
        vi dp = arr;
        // debug1(arr);
        for (int j = k - 2; j >= 0; j--)
        {
            dp[j] = max(dp[j], dp[j + 1]);
        }
        // debug1(dp);
        set<int> dic;
        dic.insert(arr[0]);
        bool found = false;
        for (int j = 1; j < k - 1 && !found; j++)
        {
            auto it = dic.upper_bound(arr[j]);
            if (it != dic.end())
            {
                int left = *it;
                if (left < dp[j + 1])
                {
                    found = true;
                }
            }
            dic.insert(arr[j]);
        }
        if (found)
            ans.pb(i);
    }

    cout << ans.size() << endl;
    for (int a : ans)
        cout << a << endl;

    return 0;
}