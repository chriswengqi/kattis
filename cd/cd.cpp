#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
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

    int n, m;
    cin >> n >> m;

    while (n != 0 && m != 0)
    {
        unordered_set<int> curr;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int c;
            cin >> c;
            curr.insert(c);
        }

        for (int i = 0; i < m; i++)
        {
            int d;
            cin >> d;
            if (curr.count(d))
                ans++;
        }

        cout << ans << endl;

        cin >> n >> m;
    }

    return 0;
}
