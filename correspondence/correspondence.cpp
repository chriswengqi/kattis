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

void debug(vs &arr)
{
    for (auto s : arr)
    {
        cout << s << " ";
    }
    cout << endl;
}

void debug(string s)
{
    cout << s << endl;
}

vector<pair<string, string>> arr;
string ans = "";
int n;

void dfs(int bitmask, string curr_s, string curr_t)
{
    if (curr_s == curr_t)
    {
        if (ans == "" || curr_s.size() < ans.size() || (curr_s.size() == ans.size() && curr_s < ans))
            ans = curr_s;
        return;
    }
    if (ans != "" && max(curr_s.size(), curr_t.size()) > ans.size())
    {
        return; // new answer alr longer than curr ans, prune, why search in the first place
    }
    for (int i = 0; i < n; i++)
    {
        if (!(bitmask & (1 << i)))
        {
            dfs(bitmask | (1 << i), curr_s + arr[i].first, curr_t + arr[i].second);
        }
    }
}

void solve(int n, int k)
{
    arr.clear();
    ans = "";
    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;
        arr.pb({s, t});
    }

    for (int i = 0; i < n; i++)
    {
        int fl = min(arr[i].first.size(), arr[i].second.size());
        if (arr[i].first.substr(0, fl) == arr[i].second.substr(0, fl))
            dfs((1 << i), arr[i].first, arr[i].second);
    }

    if (ans == "")
        cout << "Case " << k << ": "
             << "IMPOSSIBLE" << endl;
    else
    {
        cout << "Case " << k << ": " << ans << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    while (cin >> n)
    {
        solve(n, k);
        k++;
    }

    return 0;
}