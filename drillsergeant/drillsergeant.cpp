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

void debug(string s)
{
    cout << s << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<uset<int>> adj(n + 2);

    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    set<int> tree;
    umap<int, int> kv;
    tree.insert(0);
    tree.insert(n + 1);
    int curr = 0;
    int m;
    cin >> m;
    umap<int, int> pts;
    pts[0] = 3;
    pts[1] = 323;
    pts[2] = 32;
    pts[3] = 3233;
    kv[0] = 0;
    kv[n + 1] = 0;
    // cout << "here" << endl;
    for (int i = 0; i < m; i++)
    {
        int s, t;
        cin >> s >> t;
        if (s == 1)
        {
            auto prev = tree.lower_bound(t);
            prev--;
            int dont_like = 0;

            int prev_val = kv[*prev];
            if (adj[t].count(*prev))
            {
                dont_like++;
                prev_val |= 2;
            }
            else
                prev_val &= 1;
            auto next = tree.lower_bound(t);
            int next_val = kv[*next];
            if (adj[t].count(*next))
            {
                dont_like += 2;
                next_val |= 1;
            }
            else
                next_val &= 2;

            kv[t] = dont_like;
            curr += pts[kv[t]];
            curr += pts[prev_val] - pts[kv[*prev]] + pts[next_val] - pts[kv[*next]];
            kv[*prev] = prev_val;
            kv[*next] = next_val;
            tree.insert(t);
        }
        else
        {
            int curr_val = kv[t];
            auto prev = tree.lower_bound(t);
            prev--;
            auto next = tree.upper_bound(t);
            int prev_val = kv[*prev];
            int next_val = kv[*next];
            tree.erase(t);
            if (adj[*prev].count(*next))
            {
                prev_val |= 2;
                next_val |= 1;
            }
            else
            {
                prev_val &= 1;
                next_val &= 2;
            }
            // cout << t << " " << *prev << " " << *next << endl;
            curr -= pts[curr_val];
            curr += pts[prev_val] - pts[kv[*prev]] + pts[next_val] - pts[kv[*next]];
            kv[*prev] = prev_val;
            kv[*next] = next_val;
            kv.erase(t);
        }

        cout << curr << endl;
    }

    return 0;
}