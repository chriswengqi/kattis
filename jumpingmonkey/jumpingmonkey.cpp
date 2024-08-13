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

void debug(pii a)
{
    cout << a.first << " " << a.second << endl;
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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    while (n != 0 || m != 0)
    {
        vvi adj(n);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        umap<int, pii> prev; // bitmask: {prev_bitmask, prev_shot}

        int start = (1 << n) - 1;
        queue<pii> q;
        q.push({start, -1});
        bool found = false;
        while (q.size() > 0)
        {
            auto [curr, pre] = q.front();
            q.pop();
            if (curr == 0)
            {
                found = true;
                break;
            }
            for (int i = 0; i < n; i++)
            {
                int tmp = 0;
                for (int j = 0; j < n; j++)
                {
                    if (i != j && (curr & (1 << j)))
                    {
                        for (int v : adj[j])
                            tmp |= (1 << v);
                    }
                }
                if (!prev.count(tmp))
                {
                    prev[tmp] = {curr, i};
                    q.push({tmp, curr});
                    // cout << tmp << " " << curr << " " << i << endl;
                }
            }
        }

        if (!found)
            cout << "Impossible" << endl;
        else
        {
            vi ans;
            int curr = 0;
            while (curr != (1 << n) - 1)
            {
                auto [k, v] = prev[curr];
                ans.pb(v);
                curr = k;
            }
            cout << ans.size() << ": ";
            for (int i = ans.size() - 1; i >= 0; i--)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }

        cin >> n >> m;
    }

    return 0;
}