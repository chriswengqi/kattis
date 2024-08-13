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

int modmul(int a, int b, int M)
{
    int ret = a * b - M * int(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= M);
}
int modpow(int b, int e, int mod)
{
    int ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1)
            ans = modmul(ans, b, mod);
    return ans;
}

bool isPrime(int n)
{
    if (n < 2 || n % 6 % 4 != 1)
        return (n | 1) == 3;
    int A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n - 1), d = n >> s;
    for (int a : A)
    { // ^ count trailing zeroes
        int p = modpow(a % n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n - 1 && i != s)
            return 0;
    }
    return 1;
}

void solve()
{
    int n;
    double m;
    cin >> n >> m;
    vpdd arr(n + 1);
    arr[0] = {0, 0};
    for (int i = 1; i <= n; i++)
    {
        double x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }
    double dist = 0;
    int curr = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        double d = sqrt((arr[i].second - arr[i - 1].second) * (arr[i].second - arr[i - 1].second) + (arr[i].first - arr[i - 1].first) * (arr[i].first - arr[i - 1].first));
        if (dist + d > m)
        {
            break;
        }
        else
        {
            dist += d;
            curr++;
            if (isPrime(curr))
                ans = curr;
        }
    }
    cout << ans << endl;
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