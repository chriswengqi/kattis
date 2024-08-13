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
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
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

double distance(pdd x, pdd y)
{
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vpdd pts;
    for (int i = 0; i < k; i++)
    {
        double x, y;
        cin >> x >> y;
        pts.pb({x, y});
    }

    vector<tuple<double, int, int>> EL;

    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            EL.pb({distance(pts[i], pts[j]), i, j});
        }
    }

    sort(EL.begin(), EL.end());

    double ans = 0;

    int mst_cost = 0, num_taken = 0; // no edge has been taken
    UnionFind UF(k);                 // all V are disjoint sets
    // note: the runtime cost of UFDS is very light
    for (int i = 0; i < k * (k - 1) / 2; ++i)
    {                           // up to O(E)
        auto [w, u, v] = EL[i]; // C++17 style
        if (UF.isSameSet(u, v))
            continue;  // already in the same CC
        mst_cost += w; // add w of this edge
        ans = max(ans, w);
        UF.unionSet(u, v); // link them
        ++num_taken;       // 1 more edge is taken
        if (num_taken == n - k)
            break; // optimization
    }

    cout << fixed << setprecision(2) << ans << endl;
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
