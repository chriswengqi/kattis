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

vi match, vis;
vvi AL;

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

double distance(pdd p1, pdd p2)
{
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, v;
    while (cin >> n >> m >> s >> v)
    {
        vpdd gophers;
        vpdd holes;

        for (int i = 0; i < n; i++)
        {
            double x, y;
            cin >> x >> y;
            gophers.pb({x, y});
        }
        for (int i = 0; i < m; i++)
        {
            double x, y;
            cin >> x >> y;
            holes.pb({x, y});
        }
        int V = n + m;
        int Vleft = n;
        AL.assign(V, {});
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (distance(gophers[i], holes[j]) <= s * v)
                {
                    AL[i].pb(Vleft + j);
                }
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
        cout << n - MCBM << endl;
    }

    return 0;
}
