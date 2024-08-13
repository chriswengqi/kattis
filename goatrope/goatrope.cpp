#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair

double dist(int x1, int x2, int y1, int y2)
{
    double ans = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return sqrt(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    if (y <= y2 && y >= y1)
    {
        if (x < x1)
            cout << x1 - x << endl;
        else
            cout << x - x2 << endl;
        return 0;
    }
    if (x <= x2 && x >= x1)
    {
        if (y < y1)
            cout << y1 - y << endl;
        else
            cout << y - y2 << endl;
        return 0;
    }

    double ans = min(min(dist(x, x1, y, y1), dist(x, x2, y, y2)), min(dist(x, x2, y, y1), dist(x, x1, y, y2)));
    cout << ans << endl;
    return 0;
}
