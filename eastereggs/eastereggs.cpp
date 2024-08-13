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

void solve()
{
    int n, r, b;
    cin >> n >> r >> b;
    vpdd left(r);
    vpdd right(b);

    for (int i = 0; i < r; i++)
    {
        double a, b;
        cin >> a >> b;
        left[i] = {a, b};
    }

    for (int i = 0; i < b; i++)
    {
        double a, b;
        cin >> a >> b;
        right[i] = {a, b};
    }

    int V = r + b;
    int Vleft = r;
    double lb = 0;
    double rb = 1e9;
    double EPS = 1e-9;
    while (lb + EPS < rb)
    {
        vi match, vis;
        vector<set<int>> AL;

        function<int(int)> Aug = [&](int L)
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
        };
        AL.assign(V, {});
        double mid = (lb + rb) / 2;

        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < r; j++)
            {
                double dist = (left[i].first - right[j].first) * (left[i].first - right[j].first) + (left[i].second - right[j].second) * (left[i].second - right[j].second);
                if (dist + EPS <= mid * mid)
                {
                    AL[i].insert(r + j);
                }
            }
        }

        unordered_set<int> freeV;
        for (int L = 0; L < Vleft; ++L)
            freeV.insert(L); // initial assumption
        match.clear();
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

        // debug(mid);
        // debug(b + r - MCBM);

        if (b + r - MCBM < n)
        {
            rb = mid;
        }
        else
        {
            lb = mid;
        }
    }

    cout << fixed << setprecision(8) << lb << endl;
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