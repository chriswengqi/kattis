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
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

vi visited;
vvi adjList;

void dfs(int u)
{
    visited[u] = 1;

    for (int v : adjList[u])
    {
        if (visited[v] == 0)
        {
            dfs(v);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    visited.assign(n, 0);
    adjList.assign(n, vi());

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u - 1].pb(v - 1);
        adjList[v - 1].pb(u - 1);
    }

    int CC = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            CC++;
            if (CC > 1)
            {
                cout << "NO" << endl;
                return 0;
            }
            dfs(i);
        }
    }

    cout << "YES" << endl;

    return 0;
}
