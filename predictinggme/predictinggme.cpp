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
vi arr;
int ans = 0;
umap<int, int> dic;  // day: max_profit if no value on hand
umap<int, int> dic2; // day: curr if value at hand {curr - stock_val at hand}

void dfs(int day, int curr, int stock_val)
{
    if (day >= n)
    {
        ans = max(ans, curr);
        return;
    }

    if (stock_val == -1 && (!dic.count(day) || dic[day] < curr))
    {
        dic[day] = curr;
    }
    else if (stock_val != -1 && (!dic2.count(day) || dic2[day] < curr - stock_val))
    {
        dic2[day] = curr - stock_val;
    }
    else // you are worse off today than optimal without unrealised value, prune
    {
        return;
    }

    // cout << day << " " << curr << " " << stock_val << endl;

    if (stock_val == -1) // no stock;
    {
        dfs(day + 1, curr, arr[day]); // buy
        dfs(day + 1, curr, -1);       // do not buy
    }
    else
    {
        int profit = arr[day] - stock_val;
        if (profit > 0)
        {
            ans = max(curr + profit, ans);
            dfs(day + 2, curr + profit, -1);
        }

        // do not sell today
        dfs(day + 1, curr, stock_val);
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr.resize(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dfs(0, 0, -1);

    cout << ans << endl;

    return 0;
}