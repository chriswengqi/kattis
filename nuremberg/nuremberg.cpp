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

vector<vpii> adj;
vi visits;
int total_visits;
vi subtrees;
vi visited;
int ans;
vi best_ans;

int dfs(int curr, int dist)
{
    if (visited[curr])
        return 0;
    visited[curr] = 1;

    ll res = visits[curr] * dist;
    for (auto i : adj[curr])
    {
        ll next = i.first;
        ll weight = i.second;
        if (!visited[next])
        {
            res += dfs(next, dist + weight);
            subtrees[curr] += subtrees[next];
        }
    }
    subtrees[curr] += visits[curr];
    return res;
}

void reroot(int curr, int curr_ans)
{
    if (visited[curr])
        return;
    visited[curr] = 1;

    if (curr_ans < ans)
    {
        ans = curr_ans;
        best_ans = {curr};
    }
    else if (curr_ans == ans)
        best_ans.pb(curr);

    for (auto [k, v] : adj[curr])
    {
        int new_ans = curr_ans + (total_visits - subtrees[k]) * v - subtrees[k] * v;
        reroot(k, new_ans);
    }
}

void solve()
{
    int n;
    cin >> n;
    adj.assign(n + 1, vpii());
    visits.assign(n + 1, 0);
    subtrees.assign(n + 1, 0);
    visited.assign(n + 1, 0);
    total_visits = 0;
    ans = 0;
    best_ans.clear();
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w * 2});
        adj[v].pb({u, w * 2});
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int v, t;
        cin >> v >> t;
        visits[v] = t;
        total_visits += t;
    }

    ans = dfs(1, 0);
    visited.assign(n + 1, 0);
    reroot(1, ans);

    cout << ans << endl;
    sort(best_ans.begin(), best_ans.end());
    debug(best_ans);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        solve();
    }

    return 0;
}