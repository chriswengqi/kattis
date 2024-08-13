#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define LSOne(S) ((S) & -(S))

class SegmentTree
{ // OOP style
private:
    int n; // n = (int)A.size()
    vi A;  // the arrays
    vector<pair<int, int>> st, lazy;

    int l(int p) { return p << 1; }       // go to left child
    int r(int p) { return (p << 1) + 1; } // go to right child

    pair<int, int> conquer(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == -1)
            return b; // corner case
        if (b.first == -1)
            return a;
        if (a.first <= b.first)
            return a;
        return b;
    }

    void build(int p, int L, int R)
    { // O(n)
        if (L == R)
            st[p] = {A[L], L}; // base case
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
        if (lazy[p].first != -1)
        {                                          // has a lazy flag
            st[p] = lazy[p];                       // [L..R] has same value
            if (L != R)                            // not a leaf
                lazy[l(p)] = lazy[r(p)] = lazy[p]; // propagate downwards
            else                                   // L == R, a single index
                A[L] = lazy[p].first;              // time to update this
            lazy[p] = {-1, -1};                    // erase lazy flag
        }
    }

    pair<int, int> RMQ(int p, int L, int R, int i, int j)
    {                       // O(log n)
        propagate(p, L, R); // lazy propagation
        if (i > j)
            return {-1, -1}; // infeasible
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
            lazy[p] = {val, p}; // update this
            propagate(p, L, R); // lazy propagation
        }
        else
        {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
            pair<int, int> lsubtree = (lazy[l(p)].first != -1) ? lazy[l(p)] : st[l(p)];
            pair<int, int> rsubtree = (lazy[r(p)].first != -1) ? lazy[r(p)] : st[r(p)];
            st[p] = conquer(lsubtree, rsubtree);
        }
    }

public:
    SegmentTree(int sz) : n(sz), A(n), st(4 * n), lazy(4 * n, {-1, -1}) {}

    SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size())
    {
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    pair<int, int> RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};

int main()
{
    vi A = {18, 17, 13, 19, 15, 11, 20, 99}; // make n a power of 2
    SegmentTree st(A);

    printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
    printf("              A is {18,17,13,19,15,11,20,oo}\n");
    printf("RMQ(1, 3) = %d\n", st.RMQ(1, 3).second); // 13
    printf("RMQ(4, 7) = %d\n", st.RMQ(4, 7).second); // 11
    printf("RMQ(3, 4) = %d\n", st.RMQ(3, 4).second); // 15

    st.update(5, 5, 77); // update A[5] to 77
    printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
    printf("Now, modify A into {18,17,13,19,15,77,20,oo}\n");
    printf("RMQ(1, 3) = %d\n", st.RMQ(1, 3).second); // remains 13
    printf("RMQ(4, 7) = %d\n", st.RMQ(4, 7).second); // now 15
    printf("RMQ(3, 4) = %d\n", st.RMQ(3, 4).second); // remains 15

    st.update(0, 3, 30); // update A[0..3] to 30
    printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
    printf("Now, modify A into {30,30,30,30,15,77,20,oo}\n");
    printf("RMQ(1, 3) = %d\n", st.RMQ(1, 3).second); // now 30
    printf("RMQ(4, 7) = %d\n", st.RMQ(4, 7).second); // remains 15
    printf("RMQ(3, 4) = %d\n", st.RMQ(3, 4).second); // remains 15

    st.update(3, 3, 7); // update A[3] to 7
    printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
    printf("Now, modify A into {30,30,30, 7,15,77,20,oo}\n");
    printf("RMQ(1, 3) = %d\n", st.RMQ(1, 3).second); // now 7
    printf("RMQ(4, 7) = %d\n", st.RMQ(4, 7).second); // remains 15
    printf("RMQ(3, 4) = %d\n", st.RMQ(3, 4).second); // now 7

    return 0;
}