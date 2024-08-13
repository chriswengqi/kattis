#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

void solve()
{
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vi arr(8);
    vi primes{2, 3, 5, 7, 11, 13, 17, 19};
    vi power(8, 1);

    for (int i = 1; i < 8; i++)
    {
        power[i] = power[i - 1] * primes[i - 1];
    }

    int ans = 0;
    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i];
        ans += power[i] * arr[i];
    }

    cout << power.back() * primes.back() - 1 - ans << endl;

    return 0;
}
