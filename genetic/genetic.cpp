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
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vs strs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }
    vi pivots(n, 1);
    srand(time(NULL));
    while (1)
    {
        int i = rand() % n;
        if (pivots[i] == 0)
            continue;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            int dist = 0;
            for (int l = 0; l < m; l++)
            {
                if (strs[i][l] != strs[j][l])
                    dist++;
                if (dist > k)
                    break;
            }

            if (dist != k)
            {
                pivots[i] = 0;
                pivots[j] = 0;
            }
        }

        if (pivots[i] == 1)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}