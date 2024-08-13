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

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r)
{
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

vector<point> CH_Andrew(vector<point> &Pts)
{ // overall O(n log n)
    int n = Pts.size(), k = 0;
    vector<point> H(2 * n);
    sort(Pts.begin(), Pts.end()); // sort the points by x/y
    for (int i = 0; i < n; ++i)
    { // build lower hull
        while ((k >= 2) && !ccw(H[k - 2], H[k - 1], Pts[i]))
            --k;
        H[k++] = Pts[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; --i)
    { // build upper hull
        while ((k >= t) && !ccw(H[k - 2], H[k - 1], Pts[i]))
            --k;
        H[k++] = Pts[i];
    }
    H.resize(k);
    return H;
}

void solve(int n)
{
    vector<point> P;
    for (int i = 0; i < n; i++)
    {
        double a, b;
        cin >> a >> b;
        P.pb({a, b});
    }

    P = CH_Andrew(P);

    vector<point> arr;
    uset<int> dic;
    for (int i = 0; i < P.size(); i++)
    {
        if (!dic.count(P[i].x * 20001 + P[i].y))
        {
            arr.pb(P[i]);
            dic.insert(P[i].x * 20001 + P[i].y);
        }
    }

    cout << arr.size() << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i].x << " " << arr[i].y << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n != 0)
    {
        solve(n);
        cin >> n;
    }

    return 0;
}