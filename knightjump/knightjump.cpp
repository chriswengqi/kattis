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

    int n;
    cin >> n;
    vs grid(n);
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 'K')
            {
                start = i;
                end = j;
            }
        }
    }

    vpii dk{{1, -2}, {1, 2}, {2, -1}, {2, 1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};

    deque<pair<pii, int>> dq;
    dq.push_back({{start, end}, 0});

    if (start == 0 && end == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    while (dq.size() > 0)
    {
        auto [k, v] = dq.front();
        dq.pop_front();
        int x = k.first;
        int y = k.second;

        for (auto [dx, dy] : dk)
        {
            if (x + dx == 0 && y + dy == 0)
            {
                cout << v + 1 << endl;
                return 0;
            }
            if (x + dx >= 0 && x + dx < n && 0 <= y + dy && y + dy < n && grid[x + dx][y + dy] == '.')
            {
                grid[x + dx][y + dy] = '_';
                dq.push_back({{x + dx, y + dy}, v + 1});
            }
        }
    }

    cout << -1 << endl;

    return 0;
}