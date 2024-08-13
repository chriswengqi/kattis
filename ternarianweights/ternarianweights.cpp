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

vi arr;

void solve()
{
    int n;
    cin >> n;
    vi left;
    vi right;
    function<void(int)> dfs = [&](int diff)
    {
        if (diff == 0)
            return;
        int rev = 0;
        if (diff < 0)
        {
            diff = abs(diff);
            rev = 1;
        }
        int ub = lower_bound(arr.begin(), arr.end(), diff) - arr.begin();
        if (diff > arr[ub] / 2)
        {

            if (rev == 0)
            {
                right.pb(arr[ub]);
                dfs(diff - arr[ub]);
            }
            else
            {
                left.pb(arr[ub]);
                dfs(-diff + arr[ub]);
            }
        }
        else
        {
            assert(ub > 0);
            if (rev == 0)
            {
                right.pb(arr[ub - 1]);
                dfs(diff - arr[ub - 1]);
            }
            else
            {
                left.pb(arr[ub - 1]);
                dfs(-diff + arr[ub - 1]);
            }
        }
    };

    dfs(n);
    cout << "left pan: ";
    for (int a : left)
        cout << a << " ";
    cout << endl;
    cout << "right pan: ";
    for (int a : right)
        cout << a << " ";
    cout << endl;
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int curr = 1;
    while (curr < 4e9)
    {
        arr.pb(curr);
        curr *= 3;
    }
    int TC;
    cin >> TC;

    while (TC--)
    {
        solve();
    }

    return 0;
}