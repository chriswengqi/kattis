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

void solve()
{
    int n;
    cin >> n;
    string _;
    getline(cin, _);
    vvi adj(100, vi());
    umap<string, int> dic;
    vs names;
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        vs arr;
        string curr = "";
        for (char c : s)
        {
            if (c == ' ')
            {
                arr.pb(curr);
                curr = "";
            }
            else
            {
                curr.pb(c);
            }
        }
        arr.pb(curr);

        if (!dic.count(arr[0]))
        {
            dic[arr[0]] = names.size();
            names.pb(arr[0]);
        }
        int curr_idx = dic[arr[0]];
        for (int j = 1; j < arr.size(); j++)
        {
            if (!dic.count(arr[j]))
            {
                dic[arr[j]] = names.size();
                names.pb(arr[j]);
            }
            adj[curr_idx].pb(dic[arr[j]]);
        }

        debug1(names);
    }

    for (int i = 0; i < names.size(); i++)
    {
        cout << i << ": ";
        for (int v : adj[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }

    string start, end;
    cin >> start >> end;
    int curr_start = dic[start];
    vi stack;
    bool found = false;
    function<void(int, int)> dfs = [&](int u, int prev)
    {
        if (u == dic[end])
        {
            found = true;
            for (int a : stack)
            {
                cout << names[a] << " ";
            }
            cout << endl;
            return;
        }

        for (int v : adj[u])
        {
            if (v != prev)
            {
                stack.pb(v);
                dfs(v, u);
                stack.pop_back();
            }
        }
    };

    if (!found)
    {
        cout << "no route found" << endl;
    }
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