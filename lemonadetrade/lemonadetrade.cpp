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
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_map<string, double> curr;
    curr["pink"] = 0;

    for (int i = 0; i < n; i++)
    {
        string u, v;
        cin >> u >> v;
        string x;
        cin >> x;
        double d = stod(x);

        if (curr.count(v))
        {
            if (!curr.count(u))
            {
                curr[u] = curr[v] + log2(d);
            }
            else
            {
                curr[u] = max(curr[u], curr[v] + log2(d));
            }
        }
    }

    if (!curr.count("blue"))
    {
        cout << 0 << endl;
    }
    else
    {
        cout << fixed << setprecision(10) << min((double)10, pow(2, min((double)4, curr["blue"]))) << endl;
    }

    return 0;
}
