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

    int n;
    cin >> n;
    unordered_map<int, int> dic;
    unordered_map<int, int> dic2;
    int ctr1 = 0;
    int ctr2 = 0;

    UnionFind UF1(2 * n);
    UnionFind UF2(2 * n);
    bool ans1 = true;
    bool ans2 = true;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        int hash1 = 1e6 * a + 1000 * b + c;
        int hash2 = 1e6 * d + 1000 * e + f;
        if (!dic.count(hash1))
        {
            dic[hash1] = ctr1;
            ctr1++;
        }
        if (!dic.count(hash2))
        {
            dic[hash2] = ctr1;
            ctr1++;
        }
        if (UF1.isSameSet(dic[hash1], dic[hash2]))
        {
            ans1 = false;
        }
        else
        {
            UF1.unionSet(dic[hash1], dic[hash2]);
        }

        if (UF2.isSameSet(dic[hash1], dic[hash2]))
        {
            ans2 = false;
        }
        else
        {
            UF2.unionSet(dic[hash1], dic[hash2]);
        }
    }

    cout << ans1 << " " << ans2 << endl;

    return 0;
}
