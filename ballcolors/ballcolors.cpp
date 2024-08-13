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
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int m;
    cin >> m;
    uset<int> sep;
    for (int i = 0; i < m; i++)
    {
        int s;
        cin >> s;
        s--;
        sep.insert(s);
    }
    int k;
    cin >> k;
    vi adj;
    for (int i = 0; i < k; i++)
    {
        int s;
        cin >> s;
        s--;
        adj.pb(s);
    }

    int mn = LLINF;
    for (int a : adj)
    {
        mn = min(mn, arr[a]);
    }
    for (int a : adj)
    {
        arr[a] -= mn;
    }
    if (mn == 0)
    {
        cout << 0 << endl;
        return;
    }
    mn = (mn == LLINF ? 0 : mn);

    vi stars;
    int stars_ttl = 0;
    vi bars;
    int bars_ttl = 0;
    for (int i = 0; i < n; i++)
    {
        if (sep.count(i))
        {
            bars.pb(arr[i]);
            bars_ttl += arr[i];
        }
        else
        {
            stars.pb(arr[i]);
            stars_ttl += arr[i];
        }
    }
    stars.pb(mn);
    stars_ttl += mn;
    if (stars_ttl + 1 < bars_ttl)
    {
        cout << 0 << endl;
        return;
    }
    int ans = facs[stars_ttl];
    ans %= mod;
    for (int a : stars)
    {
        ans *= modInverse(facs[a], mod);
        ans %= mod;
    }
    ans *= comb(stars_ttl + 1, bars_ttl, mod);
    ans %= mod;
    ans *= facs[bars_ttl];
    ans %= mod;
    for (int a : bars)
    {
        ans *= modInverse(facs[a], mod);
        ans %= mod;
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i <= 3000; i++)
    {
        if (i == 0)
            facs.pb(1);
        else
            facs.pb((facs[i - 1] * i) % mod);
    }
    int TC;
    TC = 1;

    while (TC--)
    {
        solve();
    }

    return 0;
}