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

long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
inline long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
inline long long normalize(long long x, long long mod)
{
    x %= mod;
    if (x < 0)
        x += mod;
    return x;
}
struct GCD_type
{
    long long x, y, d;
};
GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0)
        return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}

pair<int, int> chinese_remainder_theorem(vector<int> A, vector<int> M)
{
    if (A.size() != M.size())
        return {-1, -1}; /** Invalid input*/

    for (int i = 0; i < A.size(); i++)
        normalize(A[i], M[i]);
    int ans = A[0];
    int lcm = M[0];
    for (int i = 1; i < A.size(); i++)
    {
        auto pom = ex_GCD(lcm, M[i]);
        int x1 = pom.x;
        int d = pom.d;
        if ((A[i] - ans) % d != 0)
            return {-1, -1};
        ans = normalize(ans + x1 * (A[i] - ans) / d % (M[i] / d) * lcm, lcm * M[i] / d);
        lcm = LCM(lcm, M[i]); // you can save time by replacing above lcm * n[i] /d by lcm = lcm * n[i] / d
    }
    return {ans, lcm};
}

int mod = 1e10 + 3233;

int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll extended_euclidean_gcd(ll a, ll b, ll &x, ll &y)
{ // modify x, y such that ax + by = return value gcd(a, b)
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1, g = extended_euclidean_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

ll extended_euclidean_gcd_iter(ll a, ll b, ll &x, ll &y)
{ // slightly faster than recursive version
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

ll inv_extended_euclidean(ll a, ll p)
{ // modular inverse of a mod p, i.e. x such that (a*x) === 1 (mod p)
    ll x, y;
    ll g = extended_euclidean_gcd(a, p, x, y);
    if (g != 1)
        return LONG_LONG_MAX; // modular inverse does not exist
    return (x % p + p) % p;
}

vi invs(ll m)
{ // modular inverses of 1 to m mod m, in O(m)
    vi invs(m + 1, 1);
    for (int i = 2; i <= m; ++i)
        invs[i] = (m - (m / i) * invs[m % i] % m) % m;
    return invs;
}

vi facs;
int fac = 3000301;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int ans = ((facs[(n - 1) % fac] * inv_extended_euclidean(facs[(n - k) % fac], mod)) % mod * inv_extended_euclidean(facs[(k - 1) % fac], mod)) % mod * 2;
    debug(facs[(n - 1) % fac]);
    debug(inv_extended_euclidean(facs[(n - k) % fac], mod));
    debug(inv_extended_euclidean(facs[(n - k) % fac], mod));
    cout << ans % mod << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    facs.resize(3000302, 1);

    for (int i = 1; i < 3000302; i++)
    {
        facs[i] = (facs[i - 1] * i) % mod;
    }

    while (TC--)
    {
        solve();
    }

    return 0;
}