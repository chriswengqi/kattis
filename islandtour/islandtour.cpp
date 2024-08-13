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

bool clashes(int ii, int ij, int ji, int jj)
{
    return max(ij, jj) - min(ii, ji) < (ij - ii) + (jj - ji);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi dist(n);
    vi a(n);
    vi b(n);
    vi c(n);
    for (int i = 0; i < n; i++)
        cin >> dist[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    vvi dpij(n, vi(n, 0));
    vvi dpik(n, vi(n, 0));
    vvi dpjk(n, vi(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            vpii ii(n), ij(n);
            int ti = 0;
            for (int l = i; l < i + n; l++)
            {
                ii[l % n] = {ti, ti + a[l % n]};
                ti += a[l % n] + dist[l % n];
            }
            int tj = 0;
            bool clash = false;
            for (int l = j; l < j + n; l++)
            {
                ij[l % n] = {tj, tj + b[l % n]};
                if (clashes(ii[l % n].first, ii[l % n].second, ij[l % n].first, ij[l % n].second))
                {
                    clash = true;
                    break;
                }
                tj += b[l % n] + dist[l % n];
            }
            if (!clash)
            {
                // cout << i << " " << j << endl;
                // for (auto [k, v] : ii)
                // {
                //     cout << k << "," << v << " ";
                // }
                // cout << endl;

                // for (auto [k, v] : ij)
                // {
                //     cout << k << "," << v << " ";
                // }
                // cout << endl;

                dpij[i % n][j % n] = 1;
                // debug2(dpij);
            }
        }
    }

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            vpii ij(n), ik(n);
            int tj = 0;
            bool clash = false;
            for (int l = j; l < j + n; l++)
            {
                ij[l % n] = {tj, tj + b[l % n]};
                tj += b[l % n] + dist[l % n];
            }
            int tk = 0;
            for (int l = k; l < k + n; l++)
            {
                ik[l % n] = {tk, tk + c[l % n]};
                if (clashes(ij[l % n].first, ij[l % n].second, ik[l % n].first, ik[l % n].second))
                {
                    clash = true;
                    break;
                }
                tk += c[l % n] + dist[l % n];
            }

            if (!clash)
            {
                dpjk[j % n][k % n] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            vpii ii(n), ik(n);
            int ti = 0;
            for (int l = i; l < i + n; l++)
            {
                ii[l % n] = {ti, ti + a[l % n]};
                ti += a[l % n] + dist[l % n];
            }
            int tk = 0;
            bool clash = false;
            for (int l = k; l < k + n; l++)
            {
                ik[l % n] = {tk, tk + c[l % n]};
                if (clashes(ii[l % n].first, ii[l % n].second, ik[l % n].first, ik[l % n].second))
                {
                    clash = true;
                    break;
                }
                tk += c[l % n] + dist[l % n];
            }

            if (!clash)
            {
                dpik[i % n][k % n] = 1;
            }
        }
    }
    // debug2(dpij);
    // debug2(dpik);
    // debug2(dpjk);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                if (i != j && j != k && dpij[i][j] == 1 && dpjk[j][k] == 1 && dpik[i][k] == 1)
                {
                    cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                    return 0;
                }
            }

    cout << "impossible" << endl;

    return 0;
}