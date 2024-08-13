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

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void debug(int a)
{
    cout << a << endl;
}

void debug(vi &arr)
{
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}

void debug(vvi &grid)
{
    for (vi row : grid)
    {
        for (int a : row)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}

void debug(vpii &arr)
{
    for (auto [k, v] : arr)
    {
        cout << k << " " << v << endl;
    }
}

void debug(string s)
{
    cout << s << endl;
}

int MOD = 1000000000;

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
                new_matrix[i][j] %= MOD;
            }
        }
    }

    return new_matrix;
}

vvi fast_expo(vvi matrix, int power)
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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vvi matrix{{1, 1}, {1, 0}};
    for (int i = 1; i <= n; i++)
    {
        int s, k;
        cin >> s >> k;
        vvi curr = fast_expo(matrix, k);
        cout << s << " " << curr[1][0] << endl;
    }

    return 0;
}