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
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
#define debug1(a)                           \
    for (int i = 0; i <= a.size() - 1; i++) \
    cout << a[i] << (i == a.size() - 1 ? '\n' : ' ')
#define debug2(a)                                  \
    for (int i = 0; i <= a.size() - 1; i++)        \
        for (int j = 0; j <= a[0].size() - 1; j++) \
    cout << a[i][j] << (j == a[0].size() - 1 ? '\n' : ' ')

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(string s, int curr, vi &dic)
{
    while (curr < s.size() && s[curr] != '?')
        curr++;
    if (curr == s.size())
    {
        dic.pb(stoi(s));
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (i == 0 && curr == 0 && s.size() != 1)
        {
            continue;
        }
        s[curr] = char('0' + i);
        dfs(s, curr + 1, dic);
    }
}

bool match(int a, int b, string c)
{
    int x = (int)a ^ b;
    string s = to_string(x);
    if (s.size() != c.size())
        return false;
    for (int i = 0; i < s.size(); i++)
    {
        if (c[i] == '?')
            continue;
        else if (c[i] != s[i])
            return false;
    }
    return true;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, c;
    cin >> a >> b >> b >> c >> c;
    int ans = 0;
    vi left;
    vi right;

    int aa = 0;
    int bb = 0;
    int cc = 0;
    for (char s : a)
        if (s == '?')
            aa++;
    for (char s : b)
        if (s == '?')
            bb++;
    for (char s : c)
        if (s == '?')
            cc++;

    string x, y, z;
    if (cc >= aa && cc >= bb)
    {
        z = c;
        x = a;
        y = b;
    }
    else if (bb >= aa && bb >= cc)
    {
        z = b;
        x = a;
        y = c;
    }
    else
    {
        z = a;
        x = b;
        y = c;
    }
    dfs(x, 0, left);
    dfs(y, 0, right);

    for (int s : left)
    {
        for (int t : right)
        {
            if (match(s, t, z))
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
