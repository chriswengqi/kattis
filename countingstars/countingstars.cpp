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

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int cases = 1;

    while (cin >> n >> m)
    {
        vs arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int cc = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == '-')
                {
                    // bfs
                    deque<pii> dq;
                    cc++;
                    arr[i][j] = '.';
                    dq.pb({i, j});

                    while (dq.size() > 0)
                    {
                        auto [x, y] = dq.front();
                        dq.pop_front();
                        for (auto [dx, dy] : directions)
                        {
                            if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m && arr[x + dx][y + dy] == '-')
                            {
                                dq.pb({x + dx, y + dy});
                                arr[x + dx][y + dy] = '.';
                            }
                        }
                    }
                }
            }
        }

        cout << "Case " << cases << ": " << cc << endl;
        cases++;
    }

    return 0;
}