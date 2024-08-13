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

struct Line
{
    double x1, y1, x2, y2;
};
pdd intersect(Line a, Line b)
{
    pdd A = {a.x1, a.y1};
    pdd B = {a.x2, a.y2};
    pdd C = {b.x1, b.y1};
    pdd D = {b.x2, b.y2};
    // Line AB represented as a1x + b1y = c1
    double a1 = B.second - A.second;
    double b1 = A.first - B.first;
    double c1 = a1 * (A.first) + b1 * (A.second);

    // Line CD represented as a2x + b2y = c2
    double a2 = D.second - C.second;
    double b2 = C.first - D.first;
    double c2 = a2 * (C.first) + b2 * (C.second);

    double determinant = a1 * b2 - a2 * b1;
    debug(determinant);

    if (determinant == 0)
    {
        // The lines are parallel. This is simplified
        // by returning a pair of FLT_MAX
        return make_pair(FLT_MAX, FLT_MAX);
    }
    else
    {
        double x = (b2 * c1 - b1 * c2) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
        return make_pair(x, y);
    }
}
double distance(pdd a, pdd b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
double herons(pdd a, pdd b, pdd c)
{
    double s1 = distance(a, b);
    double s2 = distance(a, c);
    double s3 = distance(b, c);

    double s = (s1 + s2 - s3) / 2;
    return sqrt(s * (s - s1) * (s - s2) * (s - s3));
}

void solve()
{
    int n;
    cin >> n;
    vector<Line> lines(n);
    for (int i = 0; i < n; i++)
    {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        lines[i] = Line{a, b, c, d};
    }
    double ans = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                pdd A = intersect(lines[i], lines[j]);
                pdd B = intersect(lines[j], lines[k]);
                pdd C = intersect(lines[i], lines[k]);
                debug(A.first);
                debug(A.second);
                debug(B.first);
                debug(B.second);
                debug(C.first);
                debug(C.second);
                if (A.first == FLT_MAX || B.first == FLT_MAX || C.first == FLT_MAX)
                    continue;
                if (A == B || A == C || B == C)
                    continue;
                ans = max(herons(A, B, C), ans);
            }
        }
    }

    if (ans == -1)
    {
        cout << "no triangle" << endl;
    }
    else
        cout << fixed << setprecision(10) << ans << endl;
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