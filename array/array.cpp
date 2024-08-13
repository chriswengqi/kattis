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

int mod = 1000000007;

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

// Function to find modular inverse of a under modulo m
// Assumption: m is prime
int modInverse(int a, int m) { return power(a, m - 2, m); }

vi facs;

// Function to perform Modular Division
int modDiv(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    return (inv * a) % m;
}

int comb(int n, int k, int mod)
{
    int ans = modDiv(facs[n], facs[k], mod);
    ans = modDiv(ans, facs[n - k], mod);
    return ans % mod;
}

void solve()
{
    facs.resize(100001, 1);
    for (int i = 1; i <= 100000; i++)
    {
        facs[i] = (facs[i - 1] * i) % mod;
    }
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (comb(n - 1, i, mod) * comb(n, i + 1, mod) * (i == 0 ? 1 : 2)) % mod;
        ans %= mod;
    }

    cout << ans << endl;
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