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

vector<int> manacher_odd(string s)
{
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = max(0LL, min(r - i, p[l + (r - i)]));
        while (s[i - p[i]] == s[i + p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > r)
        {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s)
{
    string t;
    for (auto c : s)
    {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (cin >> s)
    {
        vi odd(s.size());
        vi even(s.size());
        vi mm = manacher(s);

        for (int i = 0; i < mm.size(); i++)
        {
            if (i % 2 == 0)
            {
                odd[i / 2] = (mm[i] - 1) / 2;
            }
            else
            {
                even[i / 2] = mm[i] / 2;
            }
        }
        set<string> ans;
        for (int i = 0; i < odd.size(); i++)
        {
            for (int j = 1; j <= odd[i]; j++)
            {
                ans.insert(s.substr(i - j, 2 * j + 1));
            }
        }
        for (int i = 0; i < even.size(); i++)
        {
            for (int j = 1; j <= even[i]; j++)
            {
                ans.insert(s.substr(i - j + 1, 2 * j));
            }
        }

        for (string s : ans)
        {
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}