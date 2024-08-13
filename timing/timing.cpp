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

vvd multiply(vvd &matrix1, vvd &matrix2)
{
    int n = matrix1.size();
    vvd new_matrix(n, vd(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                new_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return new_matrix;
}

vvd fast_expo(vvd matrix, int power)
{
    int n = matrix.size();
    vvd curr(n, vd(n, 0.0));

    for (int i = 0; i < n; i++)
    {
        curr[i][i] = 1.0;
    }

    while (power > 0)
    {
        if (power & 1)
            curr = multiply(curr, matrix);
        matrix = multiply(matrix, matrix);
        power >>= 1;
    }

    return curr;
}

void solve()
{
    int n, l, t;
    cin >> n >> l >> t;
    vd arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vvi adjList(n, vi());
    vector<vd> adj(n, vd(n, 0));

    for (int i = 0; i < l; i++)
    {
        int u, v;
        double p;
        cin >> u >> v >> p;
        adjList[u].pb(v);
        adjList[v].pb(u);
        adj[v][u] = p;
    }

    for (int i = 0; i < n; i++)
    {
        double ttl = 0.0;
        for (int j = 0; j < n; j++)
        {
            ttl += adj[j][i];
        }
        adj[i][i] = 1.0 - ttl;
    }
    vvd expo = fast_expo(adj, t);
    vd new_val(n, 0.0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            new_val[i] += expo[i][j] * arr[j];
        }
    }
    double ans = INF;
    for (int i = 0; i < n; i++)
    {
        double curr = new_val[i];
        for (int a : adjList[i])
        {
            curr += new_val[a];
        }
        ans = min(curr, ans);
    }

    cout << fixed << setprecision(10) << ans << endl;
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