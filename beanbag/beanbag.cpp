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

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    int ttl = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ttl += arr[i];
    }
    int q;
    cin >> q;
    vi farms(q);
    for (int i = 0; i < q; i++)
    {
        int s;
        cin >> s;
        int val = 0;
        for (int j = 0; j < s; j++)
        {
            int t;
            cin >> t;
            t--;
            val |= (1LL << t);
        }
        farms[i] = val;
    }
    int collude = LLINF;
    for (int i = 1; i <= ((1 << n) - 1); i++)
    {
        int curr = i;
        bool can = true;
        for (int a : farms)
        {
            if (!(curr & a))
                can = false;
        }

        if (can)
        {
            int coll = 0;
            for (int j = 0; j < n; j++)
            {
                if ((1LL << j) & curr)
                {
                    coll += arr[j];
                    if (coll > collude)
                    {
                        break;
                    }
                }
            }
            collude = min(collude, coll);
        }
    }

    assert(collude != LLINF);

    cout << ttl - collude << endl;
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