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
    int n, m;
    cin >> n >> m;
    vi assignment(n + 1, 0);
    vvi adj(n + 1, vi());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int j = 0; j < 10; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            int curr = assignment[i];
            int ttl = 0;
            for (int v : adj[i])
            {
                if (assignment[v] == curr)
                    ttl++;
            }
            if (ttl > 1)
                assignment[i] = 1 - assignment[i];
        }
    }

    vi a;
    vi b;
    for (int i = 1; i <= n; i++)
    {
        if (assignment[i] == 0)
            a.pb(i);
        else
            b.pb(i);
    }

    assert(a.size() > 0);

    if (b.size() != 0)
    {
        cout << 2 << endl;
        for (int aa : a)
            cout << aa << " ";
        cout << endl;
        for (int bb : b)
            cout << bb << " ";
        cout << endl;
    }
    else
    {
        cout << 1 << endl;
        for (int aa : a)
            cout << aa << " ";
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    TC = 1;

    while (TC--)
    {
        solve();
    }

    return 0;
}