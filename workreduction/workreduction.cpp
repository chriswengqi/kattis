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

void solve(int i)
{
    int x, y, z;
    cin >> x >> y >> z;
    vpii costs;
    int ctr = 0;
    while (x >= y)
    {
        costs.pb({x - y, ctr});
        ctr++;
        x = x / 2;
    };
    vector<pair<int, string>> op;

    for (int i = 0; i < z; i++)
    {
        vc name;
        char s;
        cin >> s;
        while (s != ':')
        {
            name.pb(s);
            cin >> s;
        }
        char _;
        int a, b;
        cin >> a >> _ >> b;

        string com(name.begin(), name.end());

        int ans = 1e18;
        for (auto &[k, v] : costs)
        {
            ans = min(ans, k * a + v * b);
        }
        op.pb({ans, com});
    }

    sort(op.begin(), op.end());

    cout << "Case " << i << endl;
    for (auto &[k, v] : op)
    {
        cout << v << " " << k << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    for (int i = 1; i <= TC; i++)
    {
        solve(i);
    }

    return 0;
}
