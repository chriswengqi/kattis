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

int inv_mod(int a, int m)
{
    // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
    int g = m, r = a, x = 0, y = 1;

    while (r != 0)
    {
        int q = g / r;
        g %= r;
        swap(g, r);
        x -= q * y;
        swap(x, y);
    }

    assert(g == 1);
    assert(y == m || y == -m);
    return x < 0 ? x + m : x;
}

int chinese_remainder_theorem(int a1, int m1, int a2, int m2)
{
    if (m1 < m2)
        return chinese_remainder_theorem(a2, m2, a1, m1);

    // assert(__gcd(m1, m2) == 1);
    assert(m1 >= m2);
    int k = (a2 - a1) % m2 * inv_mod(m1, m2) % m2;
    int result = a1 + k * m1;

    if (result < 0)
        result += m1 * m2;

    assert(0 <= result && result < m1 * m2);
    assert(result % m1 == a1 && result % m2 == a2);
    return result;
}
void solve()
{
    int a, n, b, m;
    cin >> a >> n >> b >> m;
    cout << chinese_remainder_theorem(a, n, b, m) << " " << n * m << endl;
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