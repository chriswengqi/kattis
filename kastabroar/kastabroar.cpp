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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    UnionFind UF(n);
    vpii extra;
    unordered_set<int> sets;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (UF.isSameSet(u, v))
        {
            extra.pb({u, v});
        }
        else
        {
            UF.unionSet(u, v);
        }
    }

    for (int i = 0; i < n; i++)
    {
        sets.insert(UF.findSet(i));
    }

    vi set_arr(sets.begin(), sets.end());
    int main = set_arr[0];

    if (UF.numDisjointSets() - 1 > extra.size())
    {
        cout << "Nej" << endl;
    }
    else
    {
        cout << "Ja" << endl;
        int ans = UF.numDisjointSets();
        cout << ans - 1 << endl;
        while (ans > 1)
        {
            cout << extra.back().first + 1 << " " << extra.back().second + 1 << " ";
            cout << main + 1 << " " << set_arr.back() + 1 << endl;
            set_arr.pop_back();
            extra.pop_back();
            ans--;
        }
    }

    return 0;
}
