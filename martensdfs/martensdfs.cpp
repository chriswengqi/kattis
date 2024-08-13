#include <bits/stdc++.h>

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
    int n, k;
    cin >> n >> k;
    vector<uset<int>> adj(n, uset<int>());
    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vi seq;
    int q;
    while (cin >> q)
    {
        if (q >= n)
        {
            cout << "NO" << endl;
            return;
        }
        seq.pb(q);
    }

    if (seq.size() != n)
    {
        cout << "NO" << endl;
        return;
    }
    vi stack;
    vi visited(n, 0);
    stack.pb(seq[0]);
    visited[seq[0]] = 1;
    for (int i = 1; i < seq.size(); i++)
    {
        while (stack.size() > 0)
        {
            if (adj[stack.back()].count(seq[i]))
            {
                break;
            }
            for (int u : adj[stack.back()])
            {
                if (visited[u] == 0)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
            stack.pop_back();
        }

        if (stack.size() == 0)
        {
            cout << "NO" << endl;
            return;
        }

        visited[seq[i]] = 1;
        stack.pb(seq[i]);
    }
    cout << "YES" << endl;
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