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
    int n;
    cin >> n;
    vpii arr(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }
    vector<iii> EL;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            EL.pb({abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second), i, j});
        }
    }

    sort(EL.begin(), EL.end());

    int mst_cost = 0, num_taken = 0; // no edge has been taken
    UnionFind UF(n);                 // all V are disjoint sets
    // note: the runtime cost of UFDS is very light
    for (int i = 0; i < n * (n - 1) / 2; ++i)
    {                           // up to O(E)
        auto [w, u, v] = EL[i]; // C++17 style
        if (UF.isSameSet(u, v))
            continue;      // already in the same CC
        mst_cost += w;     // add w of this edge
        UF.unionSet(u, v); // link them
        ++num_taken;       // 1 more edge is taken
        if (num_taken == n - 1)
            break; // optimization
    }

    cout << mst_cost * 2 << endl;
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