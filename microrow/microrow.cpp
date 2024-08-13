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

    int n;
    cin >> n;
    vpii arr(n);
    umap<int, int> dic;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
        dic[a * 1e9 + b] = i;
    }
    sort(arr.begin(), arr.end());
    map<int, int> tree; // {max_val, all_elements}
    vvi rows;
    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        if (tree.size() == 0 || arr[i].second < (*tree.begin()).first)
        {
            tree[arr[i].second] = ctr;
            rows.pb({i});
            ctr++;
        }
        else
        {
            auto it = tree.upper_bound(arr[i].second);
            it--;
            auto [k, v] = *it;
            tree.erase(it);
            tree[arr[i].second] = v;
            rows[v].pb(i);
        }
    }

    vi ans(n);

    for (int i = 0; i < rows.size(); i++)
    {
        for (int a : rows[i])
        {
            auto [x, y] = arr[a];
            int real_i = dic[x * 1e9 + y];
            ans[real_i] = i + 1;
        }
    }
    debug(ans);
    return 0;
}