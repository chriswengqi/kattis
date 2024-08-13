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

    int c, p;
    cin >> c >> p;
    vi arr(c);
    vector<vvi> configs{{{0}, {0, 0, 0, 0}}, {{0, 0}}, {{0, 0, 1}, {1, 0}}, {{1, 0, 0}, {0, 1}}, {{0, 0, 0}, {1, 0, 1}, {0, 1}, {1, 0}}, {{0, 0, 0}, {0, 0}, {2, 0}, {0, 1, 1}}, {{0, 0, 0}, {0, 2}, {0, 0}, {1, 1, 0}}};
    assert(configs.size() == 7);
    for (int i = 0; i < c; i++)
    {
        cin >> arr[i];
    }

    p--;
    int ans = 0;

    for (vi p : configs[p])
    {
        for (int i = 0; i <= c - p.size(); i++)
        {
            vi curr(p.size(), 0);
            for (int j = 0; j < p.size(); j++)
            {
                curr[j] = arr[i + j] - p[j];
            }
            bool can = true;
            for (int i = 1; i < curr.size() && can; i++)
            {
                if (curr[i] != curr[i - 1])
                    can = false;
            }
            if (can)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}