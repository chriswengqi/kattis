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

vvi multiply(vvi &matrix1, vvi &matrix2)
{
    int n = matrix1.size();
    vvi new_matrix(n, vi(n, 0));

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

vvi fast_expo(vvi &matrix, int power)
{
    int n = matrix.size();
    vvi curr(n, vi(n, 0));

    for (int i = 0; i < n; i++)
    {
        curr[i][i] = 1;
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
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vvi mat(n, vi(n, 0));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        mat[u][v] = mat[v][u] = 1;
    }

    vvi vec(n, vi(1, 0));
    vec[s][0]++;
    vvi expo = fast_expo(mat, t);
    vvi ans = multiply(expo, vec);
    int ttl = 0;
    for (int i = 0; i < n; i++)
    {
        ttl += ans[i][0];
    }

    cout << ttl << endl;
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