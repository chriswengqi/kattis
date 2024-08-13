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

class SegmentTree
{ // OOP style
private:
    int n;                    // n = (int)A.size()
    vi A, st, st2, st3, lazy; // the arrays

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
            st3[p] = (lsubtree <= rsubtree) ? st3[l(p)] : st3[r(p)];
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

void solve(int n)
{
    vpii arr(n);
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        arr[i] = {s, i};
    }
    vi comp(n);
    sort(arr.begin(), arr.end());
    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && arr[i].first == arr[i - 1].first)
        {
            comp[arr[i].second] = ctr;
        }
        else
        {
            ctr++;
            comp[arr[i].second] = ctr;
        }
    }
    // for (int a : comp)
    // {
    //     cout << a << " ";
    // }
    // cout << endl;
    SegmentTree st(100001);

    for (int i = 0; i < n; i++)
    {
        }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (cin >> n)
    {
        solve(n);
    }

    return 0;
}
