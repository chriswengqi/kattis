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

vector<bool> prime;

void sieve(int maximum)
{
    maximum = max(maximum, 1LL);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p <= maximum; p++)
        if (prime[p])
        {
            for (int i = p * p; i <= maximum; i += p)
                if (prime[i])
                {
                    prime[i] = false;
                }
        }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    sieve(n);
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (prime[i])
            ans++;
    }
    cout << ans << endl;
    for (int i = 0; i < m; i++)
    {
        int s;
        cin >> s;
        cout << (prime[s] ? 1 : 0) << endl;
    }
    return 0;
}