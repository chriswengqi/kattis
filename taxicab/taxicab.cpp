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

vi match, vis; // global variables
vector<set<int>> AL;

int Aug(int L)
{
    if (vis[L])
        return 0; // L visited, return 0
    vis[L] = 1;
    for (auto &R : AL[L])
        if ((match[R] == -1) || Aug(match[R]))
        {
            match[R] = L; // flip status
            return 1;     // found 1 matching
        }
    return 0; // no matching
}

struct Start
{
    int time;
    int x;
    int y;
};

struct End
{
    int time;
    int x;
    int y;
};

void solve()
{
    int n;
    cin >> n;
    vector<Start> starts;
    vector<End> ends;
    vvi adj(n * 2, vi());
    int prev = -1;
    for (int i = 0; i < n; i++)
    {
        string s;
        int a, b, c, d;
        cin >> s >> a >> b >> c >> d;
        int hr = stoi(s.substr(0, 2));
        int min = stoi(s.substr(3, 2));
        int curr = hr * 60 + min;
        if (curr < prev)
        {
            curr += 24 * 60;
        }
        starts.pb({curr, a, b});
        ends.pb({curr + abs(a - c) + abs(b - d), c, d});
        prev = curr;
        adj[i].pb(i + n);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << starts[i].time << " " << starts[i].x << " " << starts[i].y << endl;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << ends[i].time << " " << ends[i].x << " " << ends[i].y << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                int dst_x = starts[i].x;
                int dst_y = starts[i].y;
                int src_x = ends[j].x;
                int src_y = ends[j].y;
                if (ends[j].time + abs(dst_x - src_x) + abs(dst_y - src_y) < starts[i].time)
                {
                    adj[j + n].pb(i);
                }
            }
        }
    }

    // for (int i = 0; i < adj.size(); i++)
    // {
    //     cout << i << ": ";
    //     for (int j : adj[i])
    //         cout << j << " ";
    //     cout << endl;
    // }

    int V = n * 4;
    int Vleft = n * 2;
    AL.assign(V, {});

    for (int i = 0; i < 2 * n; i++)
    {
        for (int j : adj[i])
        {
            AL[i].insert(j + 2 * n);
        }
    }

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

    cout << 2 * n - MCBM << endl;
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