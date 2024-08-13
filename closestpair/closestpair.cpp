#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define double ld
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

template <class T>
int sgn(T x) { return (x > 0) - (x < 0); }
template <class T>
struct Point
{
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); } // makes dist()=1
    P perp() const { return P(-y, x); }       // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const
    {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream &operator<<(ostream &os, P p)
    {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

typedef Point<double> P;
vector<P> convexHull(vector<P> pts)
{
    if (sz(pts) <= 1)
        return pts;
    sort(all(pts));
    vector<P> h(sz(pts) + 1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (P p : pts)
        {
            while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0)
                t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

array<P, 2> hullDiameter(vector<P> S)
{
    int n = sz(S), j = n < 2 ? 0 : 1;
    pair<ll, array<P, 2>> res({0, {S[0], S[0]}});
    rep(i, 0, j) for (;; j = (j + 1) % n)
    {
        res = max(res, {(S[i] - S[j]).dist2(), {S[i], S[j]}});
        if ((S[(j + 1) % n] - S[j]).cross(S[i + 1] - S[i]) >= 0)
            break;
    }
    return res.second;
}

pair<P, P> closest(vector<P> v)
{
    assert(sz(v) > 1);
    multiset<P> S;
    sort(all(v), [](P a, P b)
         { return a.y < b.y; });
    pair<ll, pair<P, P>> ret{LLONG_MAX, {P(), P()}};
    int j = 0;
    for (P p : v)
    {
        P d{1 + (ll)sqrt(ret.first), 0};
        while (v[j].y <= p.y - d.x)
            S.erase(v[j++]);
        auto lo = S.lower_bound(p - d), hi = S.upper_bound(p + d);
        for (; lo != hi; ++lo)
            ret = min(ret, {(*lo - p).dist2(), {*lo, p}});
        S.insert(p);
    }
    return ret.second;
}

double dist(P p, P q)
{
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

void solve(int n)
{
    vector<P> pts;
    for (int i = 0; i < n; i++)
    {
        double p, q;
        cin >> p >> q;
        pts.pb(P(p, q));
    }
    pair<P, P> ans = closest(pts);

    cout << fixed << setprecision(2) << ans.first.x << " " << ans.first.y << " " << ans.second.x << " " << ans.second.y << endl;
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