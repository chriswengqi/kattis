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

int mod = 10e9 + 7;

struct modint
{
    int n;
    modint() : n(0) { ; }
    modint(ll m)
    {
        if (m < 0 || mod <= m)
        {
            m %= mod;
            if (m < 0)
                m += mod;
        }
        n = m;
    }
    operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
bool operator<(modint a, modint b) { return a.n < b.n; }
modint operator+=(modint &a, modint b)
{
    a.n += b.n;
    if (a.n >= mod)
        a.n -= mod;
    return a;
}
modint operator-=(modint &a, modint b)
{
    a.n -= b.n;
    if (a.n < 0)
        a.n += mod;
    return a;
}
modint operator*=(modint &a, modint b)
{
    a.n = ((ll)a.n * b.n) % mod;
    return a;
}
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n)
{
    if (n == 0)
        return modint(1);
    modint res = (a * a) ^ (n / 2);
    if (n % 2)
        res = res * a;
    return res;
}

ll inv(ll a, ll p)
{
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint &a, modint b)
{
    a = a / b;
    return a;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}