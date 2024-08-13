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

void debug(vpii &arr)
{
    for (auto [k, v] : arr)
    {
        cout << k << " " << v << endl;
    }
}

void debug(string s)
{
    cout << s << endl;
}

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
    vvi adj(n, vi());
    vi arr(n, 0);
    vi deg(n, 0);
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        arr[i] = s;
        if (s != -1)
        {
            adj[s].pb(i);
            deg[s]++;
        }
    }
    UnionFind uf(n);
    umap<int, int> dic;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            queue<pii> q;
            q.push({i, 0});

            int best = -1;
            int best_length = 1e6;
            vi st;
            while (q.size() > 0)
            {
                auto [curr, length] = q.front();
                q.pop();
                if (deg[curr] == 0 && length < best_length)
                {
                    best = curr;
                    best_length = length;
                }
                else if (deg[curr] == 0 && length == best_length && curr < best)
                {
                    best = curr;
                }
                if (deg[curr] == 0)
                {
                    st.pb(curr);
                }
                for (int a : adj[curr])
                {
                    q.push({a, length + 1});
                }
            }

            for (int a : st)
            {
                uf.unionSet(best, a);
            }
            dic[uf.findSet(best)] = best;
        }
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int s;
        cin >> s;
        cout << dic[uf.findSet(s)] << endl;
    }

    return 0;
}