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

void solve()
{
    int n;
    cin >> n;
    unordered_map<string, int> dic;

    for (int i = 0; i < n; i++)
    {
        string s;
        int t;
        cin >> s >> t;
        if (!dic.count(s))
        {
            dic[s] = 0;
        }
        dic[s] += t;
    }

    vector<pair<int, string>> ans;

    for (auto &[k, v] : dic)
    {
        ans.pb({-v, k});
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;

    for (auto &[k, v] : ans)
    {
        cout << v << " " << -k << endl;
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
