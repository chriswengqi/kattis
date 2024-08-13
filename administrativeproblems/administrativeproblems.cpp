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

void solve()
{
    int n, m;
    cin >> n >> m;
    umap<string, iii> cars;
    umap<string, string> carStatuses;
    for (int i = 0; i < n; i++)
    {
        string s;
        int p, q, k;
        cin >> s >> p >> q >> k;
        cars[s] = {p, q, k};
        carStatuses[s] = 'Returned';
    }

    umap<string, int> personCost;
    umap<string, string> personStatus;

    for (int i = 0; i < m; i++)
    {
        int t;
        string name, act;
        cin >> t >> name >> act;

        if (act == "p")
        {
            string c;
            cin >> c;
            if (carStatuses[c] != "Returned")
            {
                personStatus[c] = "INCONSISTENT";
                personCost[c] = -1;
            }
        }
        else if (act == "a")
        {
            int c;
            cin >> c;
        }
        else
        {
            int c;
            cin >> c;
        }
    }
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