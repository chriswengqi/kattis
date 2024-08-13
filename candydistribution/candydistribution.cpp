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

pii euclid(ll A, ll B)
{ // For A,B>=0, finds (x,y) s.t.
    // Ax+By=gcd(A,B), |Ax|,|By|<=AB/gcd(A,B)
    if (!B)
        return {1, 0};
    pii p = euclid(B, A % B);
    return {p.second, p.first - A / B * p.second};
}
int invGeneral(ll A, ll B)
{ // find x in [0,B) such that Ax=1 mod B
    pii p = euclid(A, B);
    assert(p.first * A + p.second * B == 1);
    return p.first + (p.first < 0) * B;
} // must have gcd(A,B)=1

void solve()
{
    int a, b;
    cin >> a >> b;
    if (__gcd(a, b) != 1)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        int ans = invGeneral(a, b);
        assert(b > ans);
        cout << ((b - ans) * a + 1) / b << endl;
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