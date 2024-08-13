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

void debug(string s)
{
    cout << s << endl;
}

int n, r, p;
umap<int, int> dic;
int dfs(int sz)
{
    if (sz == 1)
        return 0;
    else if (dic.count(sz))
        return dic[sz];
    int ans = 1e18;
    for (int i = 2; i <= sz; i++)
    {
        // add i - 1 printf statements and compile in (i - 1) * p + r time
        int new_sz = (sz + i - 1) / i; // size of blocks
        // compile in (i - 1) * p + r + time to debug block of size(new_sz)
        ans = min(ans, (i - 1) * p + r + dfs(new_sz));
    }
    dic[sz] = ans;
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> p;

    cout << dfs(n) << endl;

    return 0;
}