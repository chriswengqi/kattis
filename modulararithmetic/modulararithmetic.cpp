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

int power(int x, int y, int m)
{
    if (y == 0)
        return 1;
    long p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    if (y % 2 == 0)
        return p;
    else
        return (x * p) % m;
}

int modInv(int a, int m)
{
    return power(a, m - 2, m);
}

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    while (n != 0 || k != 0)
    {

        for (int i = 0; i < k; i++)
        {
            int a, b;
            char c;
            cin >> a >> c >> b;
            if (c == '*')
            {
                cout << ((a % n) * (b % n)) % n << endl;
            }
            else if (c == '+')
            {
                cout << (a + b) % n << endl;
            }
            else if (c == '-')
            {
                cout << ((a - b) % n + n) % n << endl;
            }
            else
            {

                int x, y;
                int g = gcd(b, n, x, y);
                if (g != 1)
                {
                    cout << -1 << endl;
                }
                else
                    cout << (a * (x % n + n) % n) % n << endl;
            }
        }

        cin >> n >> k;
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