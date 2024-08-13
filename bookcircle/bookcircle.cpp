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
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
#define debug1(a)                           \
    for (int i = 0; i <= a.size() - 1; i++) \
    cout << a[i] << (i == a.size() - 1 ? '\n' : ' ')
#define debug2(a)                                  \
    for (int i = 0; i <= a.size() - 1; i++)        \
        for (int j = 0; j <= a[0].size() - 1; j++) \
    cout << a[i][j] << (j == a[0].size() - 1 ? '\n' : ' ')

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class MCBM
{
private:
public:
    vi match, vis;
    vvi AL;
    int V, Vleft;

    MCBM(int _V, int _Vleft) : V(_V),
                               Vleft(_Vleft)
    {
        AL.assign(V, {});
    }

    void add_edge(int u, int v)
    {
        AL[u].pb(v);
    }

    int Aug(int L)
    {
        if (vis[L])
            return 0;
        vis[L] = 1;
        for (auto &R : AL[L])
            if ((match[R] == -1) || Aug(match[R]))
            {
                match[R] = L;
                return 1;
            }
        return 0;
    }

    int run()
    {
        unordered_set<int> freeV;
        for (int L = 0; L < Vleft; ++L)
            freeV.insert(L); // initial assumption
        match.assign(V, -1);
        int MCBM = 0;
        // Greedy pre-processing for trivial Augmenting Paths
        // try commenting versus un-commenting this for-loop
        for (int L = 0; L < Vleft; ++L)
        { // O(V+E)
            vi candidates;
            for (auto &R : AL[L])
                if (match[R] == -1)
                    candidates.push_back(R);
            if ((int)candidates.size() > 0)
            {
                ++MCBM;
                freeV.erase(L);                          // L is matched
                int a = rand() % (int)candidates.size(); // randomize this
                match[candidates[a]] = L;
            }
        } // for each free vertex
        for (auto &f : freeV)
        {                         // (in random order)
            vis.assign(Vleft, 0); // reset first
            MCBM += Aug(f);       // try to match f
        }

        return MCBM;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    MCBM mcbm(n + m, n);
    umap<string, int> dic;
    vvi books;
    int ctr = 0;
    for (int i = 0; i < n + m; i++)
    {
        string s;
        cin >> s;
        int t;
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            string u;
            cin >> u;
            if (!dic.count(u))
            {
                dic[u] = ctr++;
                books.pb({});
            }
            books[dic[u]].pb(i);
        }
    }

    for (int i = 0; i < ctr; i++)
    {
        mcbm.add_edge(books[i][0], books[i][1]);
    }

    cout << mcbm.run() << endl;

    return 0;
}