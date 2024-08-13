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
    string s;
    cin >> n >> s;
    char c;
    double m;
    cin >> c >> m;
    char d;
    cin >> d;
    double r;
    if (c == 'A')
    {
        r = (s[0] == 'C' ? sqrt(m / M_PI) : sqrt(m));
    }
    else
    {
        r = (s[0] == 'C' ? m / (2 * M_PI) : m / 4);
    }

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == 'C')
            r *= sqrt(2);
        else if ((s[i - 1] == 'D' && s[i] == 'S') || (s[i - 1] == 'S' && s[i] == 'D'))
            r *= sqrt(2) / 2;
        else
            r *= 0.5;
    }

    if (s.back() == 'C')
    {
        cout << fixed << setprecision(10) << (d == 'P' ? 2 * M_PI * r : M_PI * r * r) << endl;
    }
    else
    {
        cout << fixed << setprecision(10) << (d == 'P' ? 4 * r : r * r) << endl;
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