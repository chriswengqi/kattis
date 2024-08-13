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

vpii directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

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
    vi p, rank, setSize, maxx, minn; // vi p is the key part
    int numSets;

public:
    UnionFind(int N)
    {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i)
            p[i] = i;
        rank.assign(N, 0);    // optional speedup
        setSize.assign(N, 1); // optional feature
        maxx.assign(N, 0);
        minn.assign(N, 0);
        numSets = N; // optional feature
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

    int n, k;
    cin >> n >> k;
    vvi grid(n, vi(k));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> grid[i][j];
        }
    }

    vi best(n * k + 1, 1e9);
    best[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            // int i = 0;
            // int j = 0;
            vvi visited(n, vi(k, 0));
            priority_queue<iii> st;
            st.push({-grid[i][j], i, j});
            int total = 0;
            int curr_max = grid[i][j];
            while (st.size() > 0)
            {
                auto [curr, x, y] = st.top();
                // cout << x << " " << y << endl;
                st.pop();
                if (visited[x][y])
                    continue;
                visited[x][y] = 1;
                total++;
                curr_max = max(curr_max, -curr);
                best[total] = min(best[total], curr_max - grid[i][j]);
                for (const auto [dx, dy] : directions)
                {

                    if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < k && !visited[x + dx][y + dy])
                    {
                        int new_val = grid[x + dx][y + dy];
                        if (new_val >= grid[i][j])
                            st.push({-new_val, x + dx, y + dy});
                    }
                }
            }
        }
    }

    // debug(best);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int s;
        cin >> s;
        cout << best[s] << endl;
    }

    return 0;
}