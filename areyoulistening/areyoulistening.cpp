#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

double dist(double x1, double x2, double y1, double y2)
{ // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
    return hypot(x1 - x2, y1 - y2); // return double
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cx, cy, n;
    cin >> cx >> cy >> n;
    vector<tuple<int, int, int>> d;
    for (int i = 0; i < n; i++)
    {
        int x, y, r;
        cin >> x >> y >> r;
        d.pb({x, y, r});
    }

    int l = 0;
    int r = 1000;
    int ans = 0;

    while (l < r)
    {
        int mid = (l + r) / 2;
        int points = 0;
        for (auto &[x, y, rd] : d)
        {
            if (dist((double)x, (double)cx, (double)y, (double)cy) < rd + mid)
            {

                points++;
            }
        }

        if (points >= 3)
        {
            r = mid - 1;
        }
        else
        {
            ans = l;
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
