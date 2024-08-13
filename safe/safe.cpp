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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "         ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char c;
            cin >> c;
            s[i * 3 + j] = c;
        }
    }
    vs shifts;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            string s = "000000000";
            for (int k = 0; k < 3; k++)
            {
                s[i * 3 + k] = '1';
            }
            for (int k = 0; k < 3; k++)
            {
                s[k * 3 + j] = '1';
            }
            shifts.pb(s);
        }
    }
    uset<string> dic;
    queue<pair<string, int>> q;
    q.push({s, 0});

    while (q.size() > 0)
    {
        auto [curr, cnt] = q.front();
        q.pop();
        if (curr == "000000000")
        {
            cout << cnt << endl;
            return 0;
        }
        if (dic.count(curr))
        {
            continue;
        }
        dic.insert(curr);
        for (string s : shifts)
        {
            string new_s = "000000000";
            for (int i = 0; i < 9; i++)
            {
                new_s[i] += (s[i] + curr[i]) % 4;
            }
            q.push({new_s, cnt + 1});
        }
    }

    cout << -1 << endl;

    return 0;
}