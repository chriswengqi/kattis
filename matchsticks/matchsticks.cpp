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

void solve()
{
    int n;
    cin >> n;
    umap<int, int> dic;
    dic[2] = 1;
    dic[3] = 7;
    dic[4] = 4;
    dic[5] = 2;
    dic[6] = 6;
    dic[7] = 8;
    dic[8] = 10;
    dic[9] = 18;
    dic[10] = 22;
    dic[11] = 20;
    dic[12] = 28;
    dic[13] = 68;
    dic[14] = 88;
    dic[15] = 108;
    dic[16] = 188;
    dic[17] = 200;
    dic[18] = 208;
    dic[19] = 288;
    dic[20] = 688;
    dic[21] = 888;

    if (n <= 21)
    {
        cout << dic[n] << " ";
    }
    else
    {
        cout << dic[n % 7 + 14];
        for (int i = 0; i < (n - 14) / 7; i++)
            cout << 8;
        cout << " ";
    }
    if (n % 2 == 1)
    {
        cout << 7;
        n -= 3;
    }
    for (int i = 0; i < n; i += 2)
    {
        cout << 1;
    }
    cout << endl;
    // largest: 1111.... start with 7 if n % 2 == 1
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        solve();
    }

    return 0;
}