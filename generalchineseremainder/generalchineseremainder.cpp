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

void solve()
{
    int a, n, b, m;
    cin >> a >> n >> b >> m;
    pii ans = chinese_remainder_theorem({a, b}, {n, m});
    if (ans.first == -1)
    {
        cout << "no solution" << endl;
    }
    else
    {
        cout << ans.first << " " << ans.second << endl;
    }
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