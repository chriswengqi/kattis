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

string s = "F_in_Finals_stands_for_Fizz_Buzz!";
vi arr(36);

void solve()
{
    int n, k;
    cin >> n >> k;

    k = min(k, 35LL);

    function<char(int, int)> dfs = [&](int i, int j)
    {
        int length = arr[j];
        // debug(j);
        // debug(i);
        // debug(length % 3);
        if (i < 0 || i >= length)
            return '?';
        if (j == 0)
            return s[i];
        assert((length - 30) % 3 == 0);
        int seg = (length - 30) / 3;
        // seg[4]seg[17]seg[9]
        if (i < seg)
        {
            return dfs(i, j - 1);
        }
        else if (i >= seg + 4 && i < 2 * seg + 4)
        {
            return dfs(i - seg - 4, j - 1);
        }
        else if (i >= 2 * seg + 21 && i < 3 * seg + 21)
        {
            return dfs(i - 2 * seg - 21, j - 1);
        }
        else if (i >= seg && i < seg + 4)
        {
            return s[i - seg + 1];
        }
        else if (i >= 2 * seg + 4 && i < 2 * seg + 21)
        {
            return s[i - 2 * seg + 2];
        }
        else
        {
            return s[i - 3 * seg + 3];
        }
    };

    cout << dfs(n - 1, k);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    int pow = 1;
    for (int i = 0; i < 36; i++)
    {
        if (i == 0)
            arr[i] = 33;
        else
            arr[i] = arr[i - 1] + pow * 32;
        pow *= 3LL;
        // debug(arr[i] % 3);
    }

    // for (int a : arr)
    // {
    //     cout << a << " ";
    // }
    // cout << endl;

    while (TC--)
    {
        solve();
    }

    cout << endl;

    return 0;
}