#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef tuple<int, int, int> iii;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

class UnionFind
{ // OOP style
private:
    vi p, rank, setSize; // vi p is the key part
    int numSets;

public:
    UnionFind(int N)
    {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i)
            p[i] = i;
        rank.assign(N, 0);    // optional speedup
        setSize.assign(N, 1); // optional feature
        numSets = N;          // optional feature
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j)
    {
        if (isSameSet(i, j))
            return;                         // i and j are in same set
        int x = findSet(i), y = findSet(j); // find both rep items
        if (rank[x] > rank[y])
            swap(x, y); // keep x 'shorter' than y
        p[x] = y;       // set x under y
        if (rank[x] == rank[y])
            ++rank[y];            // optional speedup
        setSize[y] += setSize[x]; // combine set sizes at y
        --numSets;                // a union reduces numSets
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

void solve()
{
    int m, c;
    cin >> m >> c;
    vector<iii> EL(c * (c - 1) / 2);

    for (int i = 0; i < c * (c - 1) / 2; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        EL[i] = {w, u, v};
    }

    sort(EL.begin(), EL.end());

    int mst_cost = 0, num_taken = 0; // no edge has been taken
    UnionFind UF(c);                 // all V are disjoint sets
    // note: the runtime cost of UFDS is very light
    for (int i = 0; i < c * (c - 1) / 2; ++i)
    {                           // up to O(E)
        auto [w, u, v] = EL[i]; // C++17 style
        if (UF.isSameSet(u, v))
            continue;      // already in the same CC
        mst_cost += w;     // add w of this edge
        UF.unionSet(u, v); // link them
        ++num_taken;       // 1 more edge is taken
        if (num_taken == c - 1)
            break; // optimization
    }

    cout << (mst_cost + c <= m ? "yes" : "no") << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        solve();
    }

    return 0;
}
