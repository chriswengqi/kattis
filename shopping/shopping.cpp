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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vpii> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    int k;
    cin >> k;
    vi arr(k);
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    arr.pb(0);
    umap<int, vi> sssp;
    // run sssp for each a
    for (int a : arr)
    {
        vi sp(n, LLINF);
        sp[a] = 0;

        set<pii> pq;
        for (int i = 0; i < n; i++)
            pq.insert({sp[i], i});

        while (pq.size() > 0)
        {
            auto [d, u] = *pq.begin();
            pq.erase(pq.begin());
            for (auto [v, w] : adj[u])
            {
                if (sp[u] + w >= sp[v])
                    continue;
                pq.erase(pq.find({sp[v], v}));
                sp[v] = sp[u] + w;
                pq.insert({sp[v], v});
            }
        }

        sssp[a] = sp;
    }
    arr.pop_back();
    vi seq(k);
    iota(seq.begin(), seq.end(), 0);

    assert(sssp.count(0));
    assert(sssp.size() == k + 1);

    int ans = LLINF;
    do
    {
        int curr = sssp[0][arr[seq[0]]] + sssp[0][arr[seq[k - 1]]];

        for (int i = 1; i < k; i++)
        {
            curr += sssp[arr[seq[i - 1]]][arr[seq[i]]];
        }

        ans = min(ans, curr);

    } while (next_permutation(seq.begin(), seq.end()));

    cout << ans << endl;

    return 0;
}