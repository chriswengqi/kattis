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

const double EPS = 1e-9;

double DEG_to_RAD(double d) { return d * M_PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / M_PI; }

struct point
{
    double x, y;                                  // only used if more precision is needed
    point() { x = y = 0.0; }                      // default constructor
    point(double _x, double _y) : x(_x), y(_y) {} // user-defined
    bool operator==(point other) const
    {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
    bool operator<(const point &p) const
    {
        return x < p.x || (abs(x - p.x) < EPS && y < p.y);
    }
};

struct vec
{
    double x, y; // name: `vec' is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b)
{ // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}

double dist(point p1, point p2)
{ // Euclidean distance
    return hypot(p1.x - p2.x, p1.y - p2.y);
} // return double

// returns the perimeter of polygon P, which is the sum of
// Euclidian distances of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P)
{ // by ref for efficiency
    double ans = 0.0;
    for (int i = 0; i < (int)P.size() - 1; ++i) // note: P[n-1] = P[0]
        ans += dist(P[i], P[i + 1]);            // as we duplicate P[0]
    return ans;
}

// returns the area of polygon P
double area(const vector<point> &P)
{
    double ans = 0.0;
    for (int i = 0; i < (int)P.size() - 1; ++i) // Shoelace formula
        ans += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
    return fabs(ans) / 2.0; // only do / 2.0 here
}

void solve()
{
    int n;
    cin >> n;
    vector<point> arr;
    for (int i = 0; i < n; i++)
    {
        double a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    arr.pb(arr[0]);

    double ori = area(arr);
    double nxt;
    cin >> nxt;
    double scale = sqrt(nxt / ori);
    vector<point> new_arr;
    double minn_x = 0;
    double minn_y = 0;
    for (int i = 0; i < n; i++)
    {
        new_arr.pb({arr[i].x * scale, arr[i].y * scale});
        minn_x = min(arr[i].x * scale, minn_x);
        minn_y = min(arr[i].y * scale, minn_y);
    }

    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(10) << new_arr[i].x - minn_x << " " << new_arr[i].y - minn_y << endl;
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