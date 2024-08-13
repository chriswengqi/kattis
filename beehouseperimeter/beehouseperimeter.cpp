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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    uset<int> st;
    vvi grid(2 * n - 1, vi(2 * n - 1, 0));
    for (int i = 0; i < k; i++)
    {
        int s;
        cin >> s;
        st.insert(s);
    }
    int ctr = 1;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1 - abs(n - i - 1); j++)
        {
            grid[i][j] = ctr;
            if (st.count(ctr))
                grid[i][j] = -1;
            ctr++;
        }
    }
    int curr = 0;
    vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}};
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1 - abs(n - i - 1); j++)
        {
            if (grid[i][j] == -1)
            {
                for (auto [dx, dy] : directions)
                {
                    int x = i + dx;
                    int y = j + dy;
                    if (x >= 0 && x < 2 * n - 1 && y >= 0 && y < 2 * n - 1 && grid[x][y] == -1)
                    {
                        curr++;
                    }
                }
            }
        }
    }

    cout << 6 * st.size() - curr << endl;

    return 0;
}