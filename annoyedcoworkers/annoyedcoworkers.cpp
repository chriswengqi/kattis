#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
#define int int
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
#define aint(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define sz(x) (int)x.size()
#define INF 1e9
#define intINF 4e18
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
    int k;
    cin >> n >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < k; i++)
    {
        int a, d;
        cin >> a >> d;
        pq.push({a + d, d});
    }

    for (int i = 0; i < n; i++)
    {
        auto curr = pq.top();
        pq.pop();
        // cout << curr.first << " " << curr.first + curr.second << endl;
        pq.push({curr.first + curr.second, curr.second});
    }

    int ans = 0;

    while (pq.size() > 1)
    {
        auto [k, v] = pq.top();
        pq.pop();
        ans = max(ans, k - v);
    }

    cout << ans << endl;
    return 0;
}
