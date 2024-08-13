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

vpii directions{{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

void solve()
{
    char a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((abs(int(a - c)) + abs(int(b - d))) % 2 == 1)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        int x_diff = int(a - c);
        int y_diff = int(b - d);
        if (x_diff == 0 && y_diff == 0)
        {
            cout << 0 << " " << a << " " << b << endl;
        }
        else if (abs(x_diff) == abs(y_diff))
        {
            cout << 1 << " " << a << " " << b << " " << c << " " << d << endl;
        }
        else
        {
            cout << 2 << " " << a << " " << b << " ";
            int mid = int(a - 'A') + int(b - '1');
            for (auto [dx, dy] : directions)
            {
                int new_x = int(a - 'A') + mid * dx;
                int new_y = int(b - '1') + mid * dy;
                if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8)
                {
                    cout << (char)('A' + new_x) << " " << (char)('1' + new_y) << " " << c << " " << d << endl;
                    return;
                }
            }
            assert(false);
        }
    }
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