#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        int ncs, ne = 0;
        cin >> ncs >> ne;

        vi cs(ncs);
        double ttl_cs = 0;
        vi e(ne);
        double ttl_e = 0;
        for (int i = 0; i < ncs; i++)
        {
            cin >> cs[i];
            ttl_cs += cs[i];
        }

        for (int i = 0; i < ne; i++)
        {
            cin >> e[i];
            ttl_e += e[i];
        }

        int avg_cs = ttl_cs / ncs;
        int avg_e = ttl_e / ne;

        sort(cs.begin(), cs.end());
        int n_cs = ncs;
        int ans = 0;
        for (int i = 0; i < n_cs; i++)
        {
            if (cs[i] > avg_e && cs[i] < avg_cs)
            {
                ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
