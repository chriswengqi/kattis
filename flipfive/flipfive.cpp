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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    umap<int, int> dic;
    vi moves;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int curr = (1LL << (i * 3 + j));
            for (auto [x, y] : directions)
            {
                int dx = i + x;
                int dy = j + y;
                if (dx >= 0 && dx < 3 && dy >= 0 && dy < 3)
                {
                    curr |= (1LL << (dx * 3 + dy));
                }
            }
            moves.pb(curr);
        }
    }

    queue<pii> q;
    q.push({0, 0});
    while (q.size() > 0)
    {

        auto [curr, ttl] = q.front();
        q.pop();
        if (dic.count(curr) && dic[curr] <= ttl)
            continue;
        dic[curr] = ttl;
        for (int a : moves)
        {
            q.push({a ^ curr, ttl + 1});
        }
    }

    int n;
    cin >> n;
    for (int _ = 0; _ < n; _++)
    {
        int val = 0;
        vs grid(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> grid[i];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] == '*')
                {
                    val |= (1LL << i * 3 + j);
                }
            }
        }

        cout << dic[val] << endl;
    }

    return 0;
}