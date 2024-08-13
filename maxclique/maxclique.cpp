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
#define sz(x) (int)x.size()
#define debug1(a)                           \
    for (int i = 0; i <= a.size() - 1; i++) \
    cout << a[i] << (i == a.size() - 1 ? '\n' : ' ')
#define debug2(a)                                  \
    for (int i = 0; i <= a.size() - 1; i++)        \
        for (int j = 0; j <= a[0].size() - 1; j++) \
    cout << a[i][j] << (j == a[0].size() - 1 ? '\n' : ' ')

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

typedef vector<bitset<200>> vb;
struct Maxclique
{
    double limit = 0.025, pk = 0;
    struct Vertex
    {
        int i, d = 0;
    };
    typedef vector<Vertex> vv;
    vb e;
    vv V;
    vector<vi> C;
    vi qmax, q, S, old;
    void init(vv &r)
    {
        for (auto &v : r)
            v.d = 0;
        for (auto &v : r)
            for (auto j : r)
                v.d += e[v.i][j.i];
        sort(all(r), [](auto a, auto b)
             { return a.d > b.d; });
        int mxD = r[0].d;
        for (int i = 0; i < r.size(); i++)
            r[i].d = min(i, mxD) + 1;
    }
    void expand(vv &R, int lev = 1)
    {
        S[lev] += S[lev - 1] - old[lev];
        old[lev] = S[lev - 1];
        while (R.size() > 0)
        {
            if ((int)q.size() + R.back().d <= qmax.size())
                return;
            q.push_back(R.back().i);
            vv T;
            for (auto v : R)
                if (e[R.back().i][v.i])
                    T.push_back({v.i});
            if (sz(T))
            {
                if (S[lev]++ / ++pk < limit)
                    init(T);
                int j = 0, mxk = 1, mnk = max(sz(qmax) - sz(q) + 1, 1LL);
                C[1].clear(), C[2].clear();
                for (auto v : T)
                {
                    int k = 1;
                    auto f = [&](int i)
                    { return e[v.i][i]; };
                    while (any_of(all(C[k]), f))
                        k++;
                    if (k > mxk)
                        mxk = k, C[mxk + 1].clear();
                    if (k < mnk)
                        T[j++].i = v.i;
                    C[k].push_back(v.i);
                }
                if (j > 0)
                    T[j - 1].d = 0;
                rep(k, mnk, mxk + 1) for (int i : C[k])
                    T[j]
                        .i = i,
                    T[j++].d = k;
                expand(T, lev + 1);
            }
            else if (sz(q) > sz(qmax))
                qmax = q;
            q.pop_back(), R.pop_back();
        }
    }
    vi maxClique()
    {
        init(V), expand(V);
        return qmax;
    }
    Maxclique(vb conn) : e(conn), C(sz(e) + 1), S(sz(C)), old(S)
    {
        rep(i, 0, sz(e)) V.push_back({i});
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vb bitset(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        bitset[u].set(v, true);
        bitset[v].set(u, true);
    }

    Maxclique mc(bitset);
    cout << mc.maxClique().size() << endl;
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