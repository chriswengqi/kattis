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

    int n, m;
    cin >> n >> m;
    while (n != 0 || m != 0)
    {
        queue<pii> q;
        q.push({n * 1000 + m, 0});
        uset<int> dic;
        bool found = false;
        while (q.size() > 0)
        {
            auto [curr, moves] = q.front();
            q.pop();
            if (curr == 0)
            {
                cout << moves << endl;
                found = true;
                break;
            }
            if (dic.count(curr))
                continue;
            dic.insert(curr);

            int h = curr / 1000;
            int t = curr % 1000;

            if (t > 0)
            {
                q.push({h * 1000 + t + 1, moves + 1});
            }
            if (t > 1)
            {
                q.push({(h + 1) * 1000 + t - 2, moves + 1});
            }
            if (h > 1)
            {
                q.push({(h - 2) * 1000 + t, moves + 1});
            }
        }

        if (!found)
        {
            cout << -1 << endl;
        }

        cin >> n >> m;
    }

    return 0;
}