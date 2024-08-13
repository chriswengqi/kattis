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

void solve()
{
    int n, m;
    cin >> n >> m;
    int bits = __builtin_popcount(n);
    int msb = -1;
    for (int i = 0; i <= 60; i++)
    {
        if ((1LL << i) & n)
            msb = i;
    }
    if (bits < m)
    {
        int curr = bits;
        for (int i = 0; i <= 60; i++)
        {
            if (!((1LL << i) & n))
            {
                n |= (1LL << i);
                curr++;
            }
            if (curr == m)
            {
                break;
            }
        }
        cout << n << endl;
    }
    else
    {
        if (bits > m)
        {
            for (int i = 0; i <= 60; i++)
            {
                if ((1LL << i) & n)
                {
                    n ^= (1LL << i);
                    bits--;
                }
                if (bits == m)
                {
                    break;
                }
            }
        }
        int curr = -1;
        for (int i = 0; i <= msb; i++)
        {
            if ((1LL << i) & n)
            {
                curr = i;
            }
            else if (!((1LL << i) & n) && curr != -1)
            {
                int new_n = n;
                new_n ^= (1LL << i);
                new_n ^= (1LL << curr);
                assert(new_n > n);
                cout << new_n << endl;
                return;
            }
        }
        int new_n = (1LL << (msb + 1));
        for (int i = 0; i < m - 1; i++)
        {
            new_n |= (1LL << i);
        }
        assert(new_n > n);
        cout << new_n << endl;
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