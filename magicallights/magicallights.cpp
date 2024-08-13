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

vi arr;
vvi trees;
int cnt = 1;
vpii intervals;
#define LSOne(S) ((S) & -(S))

class FenwickTree
{ // index 0 is not used
private:
    vi ft; // internal FT is an array
public:
    FenwickTree() {}
    FenwickTree(int m) { ft.assign(m + 1, 0); } // create an empty FT

    void build(const vi &f)
    {
        int m = (int)f.size() - 1; // note f[0] is always 0
        ft.assign(m + 1, 0);
        for (int i = 1; i <= m; ++i)
        {                                  // O(m)
            ft[i] += f[i];                 // add this value
            if (i + LSOne(i) <= m)         // i has parent
                ft[i + LSOne(i)] += ft[i]; // add to that parent
        }
    }

    FenwickTree(const vi &f) { build(f); } // create FT based on f

    FenwickTree(int m, const vi &s)
    { // create FT based on s
        vi f(m + 1, 0);
        for (int i = 0; i < (int)s.size(); ++i) // do the conversion first
            ++f[s[i]];                          // in O(n)
        build(f);                               // in O(m)
    }

    ll rsq(int j)
    { // returns RSQ(1, j)
        ll sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    ll rsq(int i, int j) { return rsq(j) ^ rsq(i - 1); } // inc/exclusion

    // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
    void update(int i, ll v)
    {
        for (; i < (int)ft.size(); i += LSOne(i))
            ft[i] += v;
    }

    int select(ll k)
    { // O(log m)
        int p = 1;
        while (p * 2 < (int)ft.size())
            p *= 2;
        int i = 0;
        while (p)
        {
            if (k > ft[i + p])
            {
                k -= ft[i + p];
                i += p;
            }
            p /= 2;
        }
        return i + 1;
    }
};

void dfs(int u)
{
    int start = cnt;
    arr.pb(u);
    cnt++;
    for (int v : trees[u])
    {
        dfs(v);
    }
    int end = cnt - 1;
    intervals[u] = {start, end};
}

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    trees.resize(n + 1, vi());
    intervals.resize(n + 1);
    arr.pb(0);

    vi colors(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> colors[i];
    }

    for (int i = 2; i <= n; i++)
    {
        int s;
        cin >> s;
        trees[s].pb(i);
    }

    dfs(1);
    vvi grid(101, vi(n + 1));
    for (int i = 1; i <= n; i++)
    {
        grid[colors[i]][intervals[i].first] += 1;
    }
    vector<FenwickTree> fts(101);

    for (int i = 1; i <= 100; i++)
    {
        fts[i] = FenwickTree(grid[i]);
    }

    for (int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0)
        {
            int ans = 0;
            for (int j = 1; j <= 100; j++)
            {
                ans += (fts[j].rsq(intervals[b].first, intervals[b].second) % 2);
            }
            cout << ans << endl;
        }
        else
        {
            fts[colors[b]].update(intervals[b].first, -1);
            fts[a].update(intervals[b].first, 1);
            colors[b] = a;
        }
    }

    return 0;
}