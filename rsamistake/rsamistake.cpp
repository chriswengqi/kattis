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

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

// Note: this sieve is O(n), but the constant factor is worse than the O(n log log n) sieve due to the multiplication.
void sieve(int maximum)
{
    maximum = max(maximum, 1LL);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int i = 2; i <= maximum; i++)
    {
        if (prime[i])
        {
            smallest_factor[i] = i;
            primes.push_back(i);
        }

        for (int p : primes)
        {
            if (p > smallest_factor[i] || int64_t(i) * p > maximum)
                break;

            prime[i * p] = false;
            smallest_factor[i * p] = p;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    sieve(1000003);
    vi ans;
    vi ans2;
    for (int i = 0; i < primes.size(); i++)
    {
        if (primes[i] * primes[i] > n)
        {
            if (n != 1)
                ans.pb(n);
            break;
        }
        while (n % primes[i] == 0)
        {
            ans.pb(primes[i]);
            n /= primes[i];
        }
    }

    for (int i = 0; i < primes.size(); i++)
    {
        if (primes[i] * primes[i] > m)
        {
            if (m != 1)
                ans2.pb(m);
            break;
        }
        while (m % primes[i] == 0)
        {
            ans2.pb(primes[i]);
            m /= primes[i];
        }
    }

    // debug1(ans);
    // debug1(ans2);

    if (ans.size() == 1 && ans2.size() == 1 && ans[0] != ans2[0])
    {
        cout << "full credit" << endl;
    }
    else
    {
        for (int a : ans2)
            ans.pb(a);
        sort(ans.begin(), ans.end());
        for (int i = 1; i < ans.size(); i++)
        {
            if (ans[i] == ans[i - 1])
            {
                cout << "no credit" << endl;
                return;
            }
        }
        cout << "partial credit" << endl;
    }
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