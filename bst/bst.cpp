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
#define sz(x) (int)x.size()
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
    int ans = 0;
    map<int, int> ss;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        if (i == 0)
        {
            ss[s] = 0;
        }
        else
        {
            auto lb = ss.lower_bound(s);
            if (lb == ss.end())
            {
                auto [k, v] = *ss.rbegin();
                ss[s] = v + 1;
                ans += ss[s];
            }
            else
            {
                auto [k, v] = *lb;
                if (lb != ss.begin())
                {
                    lb--;
                    auto [k2, v2] = *lb;
                    ss[s] = max(v, v2) + 1;
                }
                else
                {
                    ss[s] = v + 1;
                }
                ans += ss[s];
            }
        }
        cout << ans << '\n';
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