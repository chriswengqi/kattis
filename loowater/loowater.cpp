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
        vi heads(n);
        vi knights(m);

        for (int i = 0; i < n; i++)
        {
            cin >> heads[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> knights[i];
        }

        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());

        int i = 0;
        int j = 0;
        int ans = 0;

        while (j < m && i < n)
        {
            if (knights[j] >= heads[i])
            {
                ans += knights[j];
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }

        if (i < n)
        {
            cout << "Loowater is doomed!" << endl;
        }
        else
        {
            cout << ans << endl;
        }

        cin >> n >> m;
    }

    return 0;
}
