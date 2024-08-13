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

typedef vector<double> vd;
const double eps = 1e-12;

vd aux;

int solveLinear(vector<vd> &A, vd &b, vd &x)
{
    int n = sz(A), m = sz(x), rank = 0, br, bc;
    if (n)
        assert(sz(A[0]) == m);
    vi col(m);
    iota(all(col), 0);

    rep(i, 0, n)
    {
        double v, bv = 0;
        rep(r, i, n) rep(c, i, m) if ((v = fabs(A[r][c])) > bv)
            br = r,
            bc = c, bv = v;
        if (bv <= eps)
        {
            rep(j, i, n) if (fabs(b[j]) > eps) return -1;
            break;
        }
        debug(i);
        swap(A[i], A[br]);
        swap(b[i], b[br]);
        swap(col[i], col[bc]);
        rep(j, 0, n) swap(A[j][i], A[j][bc]);
        bv = 1 / A[i][i];
        rep(j, i + 1, n)
        {
            double fac = A[j][i] * bv;
            b[j] -= fac * b[i];
            rep(k, i + 1, m) A[j][k] -= fac * A[i][k];
        }
        rank++;
    }

    x.assign(m, 0);
    for (int i = rank; i--;)
    {
        b[i] /= A[i][i];
        x[col[i]] = b[i];
        rep(j, 0, i) b[j] -= A[j][i] * b[i];
    }
    return rank; // (multiple solutions if rank < m)
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n != 0)
    {
        vvd mat(n, vd(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }

        vd b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vd x(n, 0);

        int ans = solveLinear(mat, b, x);

        if (ans == -1)
        {
            cout << "inconsistent" << endl;
        }
        else if (ans != n)
        {
            for (int i = 0; i < n; i++)
            {
                if (i < ans)
                    cout << "? ";
                else
                    cout << x[i];
            }
            cout << endl;
        }
        else
        {
            for (double a : x)
            {
                cout << a << " ";
            }
            cout << endl;
        }

        cin >> n;
    }

    return 0;
}