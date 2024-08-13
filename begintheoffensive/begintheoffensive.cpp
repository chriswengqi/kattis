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

class SegmentTree
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
        return a & b; // RMQ
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
    SegmentTree(int sz) : n(sz), A(n), st(4 * n), lazy(4 * n, -1) {}

    SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size())
    {
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (*min_element(arr.begin(), arr.end()) < k)
    {
        cout << -1 << endl;
        return 0;
    }

    int maxx = 1;
    int curr = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (curr & arr[i] < k)
            break;
        maxx++;
    }

    SegmentTree st(arr);
    while (maxx > 1)
    {
        bool can = true;
        for (int i = 0; i < n && can; i += maxx)
        {
            int curr = st.RMQ(i, min(n - 1, i + maxx - 1));
            if (curr < k)
                can = false;
        }

        if (can)
        {
            cout << maxx << endl;
            return 0;
        }
        maxx--;
    }

    cout << maxx << endl;

    return 0;
}