#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

int md(int a, int b, int c, int d) // manhattan distance
{
    return abs(a - c) + abs(b - d);
}

void solve()
{
    int _;
    cin >> _ >> _;
    int x, y;
    cin >> x >> y;
    pii start = {x, y};
    vpii coords;
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        coords.pb({s, t});
    }
    int minn = 100000000;
    do
    {
        int ans = md(start.first, start.second, coords[0].first, coords[0].second);
        for (int i = 1; i < n; i++)
        {
            ans += md(coords[i].first, coords[i].second, coords[i - 1].first, coords[i - 1].second);
        }
        ans += md(coords.back().first, coords.back().second, start.first, start.second);

        minn = min(ans, minn);

    } while (next_permutation(coords.begin(), coords.end()));

    cout << minn << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        solve();
    }

    return 0;
}