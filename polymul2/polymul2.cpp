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

const int N = 3e5 + 9;

const double PI = acos(-1);
struct base
{
    double a, b;
    base(double a = 0, double b = 0) : a(a), b(b) {}
    const base operator+(const base &c) const
    {
        return base(a + c.a, b + c.b);
    }
    const base operator-(const base &c) const
    {
        return base(a - c.a, b - c.b);
    }
    const base operator*(const base &c) const
    {
        return base(a * c.a - b * c.b, a * c.b + b * c.a);
    }
};
void fft(vector<base> &p, bool inv = 0)
{
    int n = p.size(), i = 0;
    for (int j = 1; j < n - 1; ++j)
    {
        for (int k = n >> 1; k > (i ^= k); k >>= 1)
            ;
        if (j < i)
            swap(p[i], p[j]);
    }
    for (int l = 1, m; (m = l << 1) <= n; l <<= 1)
    {
        double ang = 2 * PI / m;
        base wn = base(cos(ang), (inv ? 1. : -1.) * sin(ang)), w;
        for (int i = 0, j, k; i < n; i += m)
        {
            for (w = base(1, 0), j = i, k = i + l; j < k; ++j, w = w * wn)
            {
                base t = w * p[j + l];
                p[j + l] = p[j] - t;
                p[j] = p[j] + t;
            }
        }
    }
    if (inv)
        for (int i = 0; i < n; ++i)
            p[i].a /= n, p[i].b /= n;
}
vector<long long> multiply(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size(), t = n + m - 1, sz = 1;
    while (sz < t)
        sz <<= 1;
    vector<base> x(sz), y(sz), z(sz);
    for (int i = 0; i < sz; ++i)
    {
        x[i] = i < (int)a.size() ? base(a[i], 0) : base(0, 0);
        y[i] = i < (int)b.size() ? base(b[i], 0) : base(0, 0);
    }
    fft(x), fft(y);
    for (int i = 0; i < sz; ++i)
        z[i] = x[i] * y[i];
    fft(z, 1);
    vector<long long> ret(sz);
    for (int i = 0; i < sz; ++i)
        ret[i] = (long long)round(z[i].a);
    while ((int)ret.size() > 1 && ret.back() == 0)
        ret.pop_back();
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    vi arr1(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    vi arr2(m + 1);
    for (int i = 0; i < m + 1; i++)
    {
        cin >> arr2[i];
    }
    vi ans = multiply(arr1, arr2);
    cout << n + m << endl;
    debug1(ans);
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