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
#define sz(x) (int)x.size()
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

const int inf = 1LL << 62;
void floydWarshall(vvi &m)
{
    int n = sz(m);
    rep(i, 0, n) m[i][i] = min(m[i][i], 0LL);
    rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) if (m[i][k] != inf && m[k][j] != inf)
    {
        auto newDist = max(m[i][k] + m[k][j], -inf);
        m[i][j] = min(m[i][j], newDist);
    }
    rep(k, 0, n) if (m[k][k] < 0) rep(i, 0, n) rep(j, 0, n) if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    while (n != 0 || m != 0 || k != 0)
    {
        vvi adj(n, vi(n, inf));

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u][v] = min(w, adj[u][v]);
        }

        for (int i = 0; i < n; i++)
            adj[i][i] = 0;

        floydWarshall(adj);

        for (int i = 0; i < k; i++)
        {
            int u, v;
            cin >> u >> v;
            if (adj[u][v] == inf)
            {
                cout << "Impossible" << endl;
            }
            else if (adj[u][v] == -inf)
            {
                cout << "-Infinity" << endl;
            }
            else
            {
                cout << adj[u][v] << endl;
            }
        }
        cout << endl;

        cin >> n >> m >> k;
    }

    return 0;
}