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

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> dic;

    for (int i = 0; i < n; i++)
    {
        unordered_set<string> curr;
        for (int j = 0; j < m; j++)
        {
            string s;
            cin >> s;
            if (!dic.count(s))
            {
                dic[s] = 0;
            }
            if (!curr.count(s))
            {
                dic[s]++;
            }
            curr.insert(s);
        }
    }

    vs ans;

    for (auto &[k, v] : dic)
    {
        if (v == n)
        {
            ans.pb(k);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (string s : ans)
    {
        cout << s << endl;
    }

    return 0;
}
