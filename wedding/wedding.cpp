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

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct TwoSat
{
    int n;
    vector<vector<int>> adj, radj, scc;
    vector<int> sid, vis, val;
    stack<int> stk;
    int scnt;

    // n: number of variables, including negations
    TwoSat(int n) : n(n), adj(n), radj(n), sid(n), vis(n), val(n, -1) {}

    // adds an implication
    void impl(int x, int y)
    {
        adj[x].push_back(y);
        radj[y].push_back(x);
    }
    // adds a disjunction
    void vee(int x, int y)
    {
        impl(x ^ 1, y);
        impl(y ^ 1, x);
    }
    // forces variables to be equal
    void eq(int x, int y)
    {
        impl(x, y);
        impl(y, x);
        impl(x ^ 1, y ^ 1);
        impl(y ^ 1, x ^ 1);
    }
    // forces variable to be true
    void tru(int x) { impl(x ^ 1, x); }

    void dfs1(int x)
    {
        if (vis[x]++)
            return;
        for (int i = 0; i < adj[x].size(); i++)
        {
            dfs1(adj[x][i]);
        }
        stk.push(x);
    }

    void dfs2(int x)
    {
        if (!vis[x])
            return;
        vis[x] = 0;
        sid[x] = scnt;
        scc.back().push_back(x);
        for (int i = 0; i < radj[x].size(); i++)
        {
            dfs2(radj[x][i]);
        }
    }

    // returns true if satisfiable, false otherwise
    // on completion, val[x] is the assigned value of variable x
    // note, val[x] = 0 implies val[x^1] = 1
    bool two_sat()
    {
        scnt = 0;
        for (int i = 0; i < n; i++)
        {
            dfs1(i);
        }
        while (!stk.empty())
        {
            int v = stk.top();
            stk.pop();
            if (vis[v])
            {
                scc.push_back(vector<int>());
                dfs2(v);
                scnt++;
            }
        }
        for (int i = 0; i < n; i += 2)
        {
            if (sid[i] == sid[i + 1])
                return false;
        }
        vector<int> must(scnt);
        for (int i = 0; i < scnt; i++)
        {
            for (int j = 0; j < scc[i].size(); j++)
            {
                val[scc[i][j]] = must[i];
                must[sid[scc[i][j] ^ 1]] = !must[i];
            }
        }
        return true;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    TwoSat ts(2 * n);

    for (int i = 0; i < m; i++)
    {
        string s, t;
        cin >> s >> t;

        int curr_a = 2 * stoi(s.substr(0, s.size() - 1)) + (s.back() == 'h' ? 0 : 1);
        int curr_b = 2 * stoi(t.substr(0, t.size() - 1)) + (t.back() == 'h' ? 0 : 1);
        ts.vee(curr_a, curr_b);
    }

    if (!ts.two_sat())
    {
        cout << "bad luck" << endl;
        return;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        if (ts.val[2 * i] == 1)
        {
            cout << i << (ts.val[0] == 1 ? "h " : "w ");
        }
        else
        {
            cout << i << (ts.val[0] == 1 ? "w " : "h ");
        }
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    TC = 1;

    while (TC--)
    {
        solve();
    }

    return 0;
}