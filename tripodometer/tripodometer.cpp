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

    int n;
    cin >> n;
    unordered_map<int, int> dic;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        if (!dic.count(m))
        {
            dic[m] = 0;
        }
        total += m;
        dic[m]++;
    }

    cout << dic.size() << endl;
    vi ans;
    for (auto &[k, v] : dic)
    {
        ans.pb(total - k);
    }

    sort(ans.begin(), ans.end());

    for (auto &a : ans)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
