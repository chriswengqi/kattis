#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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

void solve()
{
    int n;
    cin >> n;
    vi arr(4);
    for (int i = 0; i < 4; i++)
        cin >> arr[i];
    if (n % 5 > arr[0] || (n % 10 >= 5 && arr[1] == 0 && arr[3] == 0))
    {
        cout << "Impossible" << endl;
    }
    else
    {
        int ttl = 0;
        // greedily go down
        int a = min(n / 25, arr[3]);
        n -= a * 25;
        arr[3] -= a;
        ttl += a;

        int b = min(n / 10, arr[2]);
        n -= b * 10;
        arr[2] -= b;
        ttl += b;

        int c = min(n / 5, arr[1]);
        n -= c * 5;
        arr[1] -= c;
        ttl += c;

        int d = min(n, arr[0]);
        n -= d;
        arr[0] -= d;
        ttl += d;

        assert(n == 0);

        // swap 25 with 5 5's
        int minn = min(a * 5, arr[1]);
        ttl += minn * 4;

        cout << ttl << endl;
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