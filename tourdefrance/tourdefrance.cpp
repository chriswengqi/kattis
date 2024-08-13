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
    cin >> n;

    while (n != 0)
    {
        cin >> m;
        vector<double> front(n);
        vector<double> back(m);
        for (int i = 0; i < n; i++)
        {
            cin >> front[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> back[i];
        }

        vector<double> ans;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans.pb(back[j] / front[i]);
            }
        }

        sort(ans.begin(), ans.end());

        double output = 0;

        for (int i = 1; i < n * m; i++)
        {
            output = max(output, ans[i] / ans[i - 1]);
        }

        cout << fixed << setprecision(2) << output << endl;

        cin >> n;
    }

    return 0;
}
