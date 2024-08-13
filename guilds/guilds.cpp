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

vi p;
umap<string, int> dic;
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    p.resize(n * 2);
    for (int i = 0; i < n * 2; i++)
        p[i] = i;
    vs names(n);
    vs dic2;
    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;
        if (!dic.count(s))
        {
            dic2.pb(s);
            dic[s] = ctr++;
        }
        if (!dic.count(t))
        {
            dic2.pb(t);
            dic[t] = ctr++;
        }
        names[i] = s;
        p[dic[s]] = dic[t];
    }

    for (int i = 0; i < n; i++)
    {
        int v = findSet(dic[names[i]]);
        cout << names[i] << " " << dic2[v] << endl;
    }

    return 0;
}