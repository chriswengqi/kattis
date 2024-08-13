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

    int s, p, y, j;

    while (cin >> s >> p >> y >> j)
    {
        int total = 12 + j;
        int yy = (total - p - y) / 3;
        int ss = yy + y;
        int pp = yy + p;
        vi s1{0, 1, 2};
        vi p1{0, 1};
        bool found = false;
        for (int i = 0; i < 3 && !found; i++)
        {
            for (int k = 0; k < 2 && !found; k++)
            {
                int s2 = ss + s1[i];
                int p2 = pp + p1[k];
                if (total == yy + s2 + p2 && (s2 == yy + y || s2 == yy + y + 1) && (p2 == yy + p || p2 == yy + p + 1) && (s2 == p2 + s || s2 == p2 + s + 1))
                {
                    found = true;
                    ss = s2;
                    pp = p2;
                }
            }
        }

        assert(found);

        cout << ss << " " << pp << " " << yy << endl;
    }

    return 0;
}