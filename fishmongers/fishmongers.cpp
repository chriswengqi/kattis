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

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void debug(int a)
{
    cout << a << endl;
}

void debug(vi &arr)
{
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}

void debug(vvi &grid)
{
    for (vi row : grid)
    {
        for (int a : row)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}

void debug(vpii &arr)
{
    for (auto [k, v] : arr)
    {
        cout << k << " " << v << endl;
    }
}

void debug(string s)
{
    cout << s << endl;
}

void solve()
{
    int n;
    cin >> n;
    vvi grid(n, vi(n, 2));
    debug(grid);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    vpii wants(m);
    for (int i = 0; i < m; i++)
    {
        int x, p;
        cin >> x >> p;
        wants[i] = {p, x};
    }

    sort(wants.begin(), wants.end(), greater<pii>());
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        auto [pay, num] = wants[i];
        while (arr.size() > 0 && num > 0)
        {
            ans += pay * arr.back();
            arr.pop_back();
            num--;
        }

        if (arr.size() == 0)
            break;
    }

    cout << ans << endl;

    return 0;
}