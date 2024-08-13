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
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
#define debug1(a)                           \
    for (int i = 0; i <= a.size() - 1; i++) \
    cout << a[i] << (i == a.size() - 1 ? '\n' : ' ')
#define debug2(a)                                  \
    for (int i = 0; i <= a.size() - 1; i++)        \
        for (int j = 0; j <= a[0].size() - 1; j++) \
    cout << a[i][j] << (j == a[0].size() - 1 ? '\n' : ' ')

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class SegmentTree
{ // OOP style
private:
    int n;               // n = (int)A.size()
    vi A, st, st2, lazy; // the arrays

    int l(int p) { return p << 1; }       // go to left child
    int r(int p) { return (p << 1) + 1; } // go to right child

    int conquer(int a, int b)
    {
        if (a == -1)
            return b; // corner case
        if (b == -1)
            return a;
        return min(a, b); // RMQ
    }

    int conquer2(int a, int b)
    {
        if (a == -1)
            return b; // corner case
        if (b == -1)
            return a;
        if (A[a] < A[b])
            return a;
        else
            return b;
    }

    void build(int p, int L, int R)
    { // O(n)
        if (L == R)
        {
            st[p] = A[L]; // base case
            st2[p] = L;
        }
        else
        {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
            st2[p] = conquer2(st2[l(p)], st2[r(p)]);
        }
    }

    void propagate(int p, int L, int R)
    {
        if (lazy[p] != -1)
        {                    // has a lazy flag
            st[p] = lazy[p]; // [L..R] has same value
            st2[p] = L;
            if (L != R)                            // not a leaf
                lazy[l(p)] = lazy[r(p)] = lazy[p]; // propagate downwards
            else                                   // L == R, a single index
                A[L] = lazy[p];                    // time to update this
            lazy[p] = -1;                          // erase lazy flag
        }
    }

    pii RMQ(int p, int L, int R, int i, int j)
    {                       // O(log n)
        propagate(p, L, R); // lazy propagation
        if (i > j)
            return {-1, -1}; // infeasible
        if ((L >= i) && (R <= j))
            return {st[p], st2[p]}; // found the segment
        int m = (L + R) / 2;
        auto [val1, idx1] = RMQ(l(p), L, m, i, min(m, j));
        auto [val2, idx2] = RMQ(r(p), m + 1, R, max(i, m + 1), j);
        return {conquer(val1, val2), conquer2(idx1, idx2)};
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
            st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
            st2[p] = (lsubtree <= rsubtree) ? st2[l(p)] : st2[r(p)];
        }
    }

public:
    SegmentTree(int sz) : n(sz), st(4 * n), st2(4 * n), lazy(4 * n, -1) {}

    SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size())
    {
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    // [i, j] INCLUSIVE!!
    pii RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vpii tmp(n, {-1, -1});
    umap<int, pii> dic;
    for (int i = 0; i < n; i++)
    {
        tmp[i] = {arr[i], i};
    }

    SegmentTree st(arr);

    vpii ans;

    sort(tmp.begin(), tmp.end(), greater<pii>());
    pii second = tmp[1];
    tmp.erase(tmp.begin() + 1);
    ans.pb(tmp[0]);
    uset<int> used;
    for (int i = 0; i < n - 1; i++)
    {
        auto [val1, idx1] = tmp[i];
        if (used.count(idx1))
        {
            continue;
        }
        int nxt = i + 1;
        // cout << i << " " << nxt << endl;
        while (used.count(tmp[nxt].second) && nxt < n)
        {
            nxt++;
        }
        if (nxt >= n)
            break;

        auto [val2, idx2] = tmp[nxt];
        if (max(idx1, idx2) == n - 1)
        {
            ans.pb({val2, idx2});
            continue;
        }
        auto [min_val, min_id] = st.RMQ(max(idx1, idx2) + 1, n - 1);
        if (min_id == -1 || min_id == idx2 || min_id == idx1 || min_val > min(val1, val2))
        {
            ans.pb({val2, idx2});
            continue;
        }

        debug(min_val);
        debug(min_id);

        ans.pb({min_val, min_id});
        ans.pb({val2, idx2});
        st.update(min_id, min_id, INF);
        used.insert(min_id);
    }

    // for (auto [k, v] : ans)
    // {
    //     cout << k << "," << v << " ";
    // }
    // cout << endl;

    int anss = 0;
    for (int i = 0; i < n - 2; i++)
    {
        if (ans[i].second > ans[i + 1].second)
        {
            anss += ans[i].first;
        }
        else
        {
            anss += ans[i + 1].first;
        }
    }

    cout << anss + (ans.back().second > second.second ? ans.back().first : second.first) << endl;

    return 0;
}