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

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b)
{ // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// returns the area of polygon P, which is half the cross products
// of vectors defined by edge endpoints
double area_alternative(const vector<point> &P)
{
    double ans = 0.0;
    point O(0.0, 0.0);                          // O = the Origin
    for (int i = 0; i < (int)P.size() - 1; ++i) // sum of signed areas
        ans += cross(toVec(O, P[i]), toVec(O, P[i + 1]));
    return fabs(ans) / 2.0;
}

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r)
{
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r)
{
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// returns true if we always make the same turn
// while examining all the edges of the polygon one by one
bool isConvex(const vector<point> &P)
{
    int n = (int)P.size();
    // a point/sz=2 or a line/sz=3 is not convex
    if (n <= 3)
        return false;
    bool firstTurn = ccw(P[0], P[1], P[2]); // remember one result,
    for (int i = 1; i < n - 1; ++i)         // compare with the others
        if (ccw(P[i], P[i + 1], P[(i + 2) == n ? 1 : i + 2]) != firstTurn)
            return false; // different -> concave
    return true;          // otherwise -> convex
}

// returns 1/0/-1 if point p is inside/on (vertex/edge)/outside of
// either convex/concave polygon P
int insidePolygon(point pt, const vector<point> &P)
{
    int n = (int)P.size();
    if (n <= 3)
        return -1; // avoid point or line
    bool on_polygon = false;
    for (int i = 0; i < n - 1; ++i) // on vertex/edge?
        if (fabs(dist(P[i], pt) + dist(pt, P[i + 1]) - dist(P[i], P[i + 1])) < EPS)
            on_polygon = true;
    if (on_polygon)
        return 0;     // pt is on polygon
    double sum = 0.0; // first = last point
    for (int i = 0; i < n - 1; ++i)
    {
        if (ccw(pt, P[i], P[i + 1]))
            sum += angle(P[i], pt, P[i + 1]); // left turn/ccw
        else
            sum -= angle(P[i], pt, P[i + 1]); // right turn/cw
    }
    return fabs(sum) > M_PI ? 1 : -1; // 360d->in, 0d->out
}

// compute the intersection point between line segment p-q and line A-B
point lineIntersectSeg(point p, point q, point A, point B)
{
    double a = B.y - A.y, b = A.x - B.x, c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

// cuts polygon Q along the line formed by point A->point B (order matters)
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point A, point B, const vector<point> &Q)
{
    vector<point> P;
    for (int i = 0; i < (int)Q.size(); ++i)
    {
        double left1 = cross(toVec(A, B), toVec(A, Q[i])), left2 = 0;
        if (i != (int)Q.size() - 1)
            left2 = cross(toVec(A, B), toVec(A, Q[i + 1]));
        if (left1 > -EPS)
            P.push_back(Q[i]);    // Q[i] is on the left
        if (left1 * left2 < -EPS) // crosses line AB
            P.push_back(lineIntersectSeg(Q[i], Q[i + 1], A, B));
    }
    if (!P.empty() && !(P.back() == P.front()))
        P.push_back(P.front()); // wrap around
    return P;
}

vector<point> CH_Graham(vector<point> &Pts)
{                         // overall O(n log n)
    vector<point> P(Pts); // copy all points
    int n = (int)P.size();
    if (n <= 3)
    { // point/line/triangle
        if (!(P[0] == P[n - 1]))
            P.push_back(P[0]); // corner case
        return P;              // the CH is P itself
    }

    // first, find P0 = point with lowest Y and if tie: rightmost X
    int P0 = min_element(P.begin(), P.end()) - P.begin();
    swap(P[0], P[P0]); // swap P[P0] with P[0]

    // second, sort points by angle around P0, O(n log n) for this sort
    sort(++P.begin(), P.end(), [&](point a, point b)
         {
             return ccw(P[0], a, b); // use P[0] as the pivot
         });

    // third, the ccw tests, although complex, it is just O(n)
    vector<point> S({P[n - 1], P[0], P[1]}); // initial S
    int i = 2;                               // then, we check the rest
    while (i < n)
    { // n > 3, O(n)
        int j = (int)S.size() - 1;
        if (ccw(S[j - 1], S[j], P[i])) // CCW turn
            S.push_back(P[i++]);       // accept this point
        else                           // CW turn
            S.pop_back();              // pop until a CCW turn
    }
    return S; // return the result
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
    vector<point> poly;
    for (int i = 0; i < n; i++)
    {
        double a, b;
        cin >> a >> b;
        poly.pb({a, b});
    }
    poly.pb(poly[0]);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        double a, b;
        cin >> a >> b;
        point p = {a, b};
        int ans = insidePolygon(p, poly);
        if (ans == 1)
        {
            cout << "in" << endl;
        }
        else if (ans == 0)
        {
            cout << "on" << endl;
        }
        else
        {
            cout << "out" << endl;
        }
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