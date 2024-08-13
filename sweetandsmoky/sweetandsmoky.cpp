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

    int n, m;
    cin >> n >> m;

    // idea: prefix either "", "a" or "aa" then append ba or baa behind until n and m is satisfied
    // let a and b be the number of ba and baa after removing prefix
    // solve simultaneous: 2a + 3b = n; 24a + 28b = m;

    // if odd, definitely starts with aa, then append ba or baa behind
    int a = 0;
    int b = 0; // a represents ba, b represents baa
    string ans = "";
    if (m % 2 == 1)
    {
        n -= 2;
        m -= 29;
        if (12 * n - m >= 0 && (12 * n - m) % 8 == 0)
        {
            b = (12 * n - m) / 8;
            a = (n - 3 * b) / 2;
            if (a >= 0)
            {
                cout << "aa";
                for (int i = 0; i < a; i++)
                    cout << "ba";
                for (int j = 0; j < b; j++)
                    cout << "baa";
                cout << endl;
                return 0;
            }
        }

        cout << "IMPOSSIBLE" << endl;

        return 0;
    }

    // start with "" and append ba or baa behind
    if (12 * n - m >= 0 && (12 * n - m) % 8 == 0) 
    {
        b = (12 * n - m) / 8;
        a = (n - 3 * b) / 2;
        if (a >= 0 && b > 0)
        {
            for (int j = 0; j < b; j++)
                cout << "baa";
            for (int i = 0; i < a; i++)
                cout << "ba";

            cout << endl;
            return 0;
        }
    }
    // start with a and append ba or baa behind
    n--;
    m -= 4;
    ans = "a";
    if (12 * n - m >= 0 && (12 * n - m) % 8 == 0)
    {
        b = (12 * n - m) / 8;
        a = (n - 3 * b) / 2;
        if (a >= 0)
        {
            cout << "a";
            for (int j = 0; j < b; j++)
                cout << "baa";
            for (int i = 0; i < a; i++)
                cout << "ba";
            cout << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
