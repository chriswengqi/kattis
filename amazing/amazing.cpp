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

vpii directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
// down, up, left, right
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vvi visited(200, vi(200, 0));
    vs commands{"down", "left", "up", "right"};
    string res;
    stack<int> s;

    function<bool(int, int)> dfs = [&](int x, int y)
    {
        int prev = s.top();
        for (int i = 0; i < 4; i++)
        {
            if (prev != INF && i == (prev + 2) % 4)
                continue; // do not walk back
            if (visited[x][y])
                continue;
            cout << commands[i] << endl;
            cin >> res;
            if (res == "solved")
            {
                exit(0);
                return true;
            }

            if (res == "ok")
            {
                s.push({i});
                return dfs(x + directions[i].first, y + directions[i].second);
            }
        }

        cout << commands[(prev + 2) % 4] << endl;
        s.pop();
        cin >> res;
        assert(res == "ok");

        visited[x][y] = 1;
    };

    s.push(INF);

    bool ans = dfs(100, 100);
    if (!ans && s.top() == INF)
    {
        cout << "no way out" << endl;
        cin >> res;
        assert(res == "solved");
    }

    return 0;
}