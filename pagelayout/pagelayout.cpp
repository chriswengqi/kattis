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
int n;
vi xs;
vi ys;
vi wws;
vi hs;
uset<int> bits;
int ans = 0;

bool overlap(int i, int j)
{
    if (xs[i] + wws[i] <= xs[j] || xs[j] + wws[j] <= xs[i] || ys[i] + hs[i] <= ys[j] || ys[j] + hs[j] <= ys[i])
    {
        return false;
    }
    return true;
}

void dfs(int bitmask, int curr, int curr_ans)
{
    if (curr == n)
        return;
    bool can_choose = true;
    for (int i = 0; i < curr && can_choose; i++)
    {
        if ((bitmask & (1LL << i)) && overlap(i, curr))
        {
            can_choose = false;
        }
    }

    dfs(bitmask, curr + 1, curr_ans);
    if (can_choose)
    {
        ans = max(ans, curr_ans + wws[curr] * hs[curr]);
        dfs(bitmask | (1LL << curr), curr + 1, curr_ans + wws[curr] * hs[curr]); // choose
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    while (n != 0)
    {

        ans = 0;
        wws.resize(n, 0);
        hs.resize(n, 0);
        xs.resize(n, 0);
        ys.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> wws[i] >> hs[i] >> xs[i] >> ys[i];
        }

        dfs(0, 0, 0);

        cout << ans << endl;

        cin >> n;
    }

    return 0;
}