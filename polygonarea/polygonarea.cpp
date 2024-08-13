#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll
typedef long double ld;
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
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define INF 1e9
#define LLINF 4e18
#define umap unordered_map
#define uset unordered_set
#define sz(x) (int)x.size()
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
struct Point
{
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
};

template <class T>
T polygonArea2(vector<Point<T>> &v)
{
    T a = v.back().cross(v[0]);
    for (int i = 0; i < sz(v) - 1; i++)
        a += v[i].cross(v[i + 1]);
    return a;
}

typedef Point<double> P;

void solve(int n)
{
    vector<P> pts(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pts[i] = P(a, b);
    }

    // implementation has 2x polygon area
    double area = polygonArea2(pts) / 2;
    (area < 0) ? cout << "CW " : cout << "CCW ";

    cout << fixed << setprecision(1) << abs(area) << "\n";
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