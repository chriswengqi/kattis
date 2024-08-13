#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    unordered_map<string, int> dic;
    vs arr(n);
    vvi adj(n, vi());

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        dic[s] = i;
        arr[i] = s;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string s, t;
        cin >> s >> t;
        adj[dic[s]].pb(dic[t]);
        adj[dic[t]].pb(dic[s]);
    }
    // check is bipartite
    vi side(n, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 0; st < n; ++st)
    {
        if (side[st] == -1)
        {
            q.push(st);
            side[st] = 0;
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                for (int u : adj[v])
                {
                    if (side[u] == -1)
                    {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    }
                    else
                    {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }

    if (is_bipartite)
    {
        for (int i = 0; i < n; i++)
        {
            if (side[i] == 0)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;

        for (int i = 0; i < n; i++)
        {
            if (side[i] == 1)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "impossible" << endl;
    }

    return 0;
}
