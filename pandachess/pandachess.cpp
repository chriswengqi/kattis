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

class MaxSegmentTree
{ // OOP style
private:
    int n;          // n = (int)A.size()
    vi A, st, lazy; // the arrays

    int l(int p) { return p << 1; }       // go to left child
    int r(int p) { return (p << 1) + 1; } // go to right child

    int conquer(int a, int b)
    {
        if (a == -1)
            return b; // corner case
        if (b == -1)
            return a;
        return max(a, b); // RMQ
    }

    void build(int p, int L, int R)
    { // O(n)
        if (L == R)
            st[p] = A[L]; // base case
        else
        {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    void propagate(int p, int L, int R)
    {
        if (lazy[p] != -1)
        {                                          // has a lazy flag
            st[p] = lazy[p];                       // [L..R] has same value
            if (L != R)                            // not a leaf
                lazy[l(p)] = lazy[r(p)] = lazy[p]; // propagate downwards
            else                                   // L == R, a single index
                A[L] = lazy[p];                    // time to update this
            lazy[p] = -1;                          // erase lazy flag
        }
    }

    int RMQ(int p, int L, int R, int i, int j)
    {                       // O(log n)
        propagate(p, L, R); // lazy propagation
        if (i > j)
            return -1; // infeasible
        if ((L >= i) && (R <= j))
            return st[p]; // found the segment
        int m = (L + R) / 2;
        return conquer(RMQ(l(p), L, m, i, min(m, j)),
                       RMQ(r(p), m + 1, R, max(i, m + 1), j));
    }

    void update(int p, int L, int R, int i, int j, int val)
    {                       // O(log n)
        propagate(p, L, R); // lazy propagation
        if (i > j)
            return;
        if ((L >= i) && (R <= j))
        {                       // found the segment
            lazy[p] = val;      // update this
            propagate(p, L, R); // lazy propagation
        }
        else
        {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
            int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
            int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
            st[p] = conquer(lsubtree, rsubtree);
        }
    }

public:
    MaxSegmentTree(int sz) : n(sz), A(n), st(4 * n), lazy(4 * n, -1) {}

    MaxSegmentTree(const vi &initialA) : MaxSegmentTree((int)initialA.size())
    {
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    umap<int, int> dic;
    vi arr;
    vi indeg(n * 2, 0);
    vector<uset<int>> adj(n * 2, uset<int>());
    for (int i = 0; i < m; i++)
    {
        int s, t;
        cin >> s >> t;
        if (!dic.count(s))
        {
            dic[s] = arr.size();
            arr.pb(s);
        }
        if (!dic.count(t))
        {
            dic[t] = arr.size();
            arr.pb(t);
        }
        if (!adj[dic[s]].count(dic[t]))
            indeg[dic[t]]++;
        adj[dic[s]].insert(dic[t]);
    }

    queue<int> q;
    vi toposort;
    for (int i = 0; i < arr.size(); i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
            toposort.pb(i);
        }
    }
    assert(q.size() == 1);

    while (q.size() > 0)
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            indeg[v]--;
            if (indeg[v] == 0)
            {
                toposort.pb(v);
                q.push(v);
            }
        }
    }
    assert(toposort.size() == n);
    umap<int, int> dic2;
    for (int i = 1; i <= n; i++)
    {
        dic2[toposort[i - 1]] = i;
    }

    vi seq(n);
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        if (!dic.count(s))
            seq[i] = -1;
        else
            seq[i] = dic2[dic[s]];
    }

    MaxSegmentTree st(n + 5);

    for (int i = 0; i < n; i++)
    {
        if (seq[i] > 0)
        {
            int curr = st.RMQ(0, seq[i] - 1);
            st.update(seq[i], seq[i], curr + 1);
        }
    }

    cout << (n - st.RMQ(0, n)) * 2 << endl;
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