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

    vi arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, int> dic;
    for (int i = 0; i < m; i++)
    {
        int s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s < arr[j])
                break;
            int diff = s - arr[j];
            if (!dic.count(diff))
                dic[diff] = 0;
            dic[diff]++;
        }
    }
    int curr_max = 0;
    int ans = 0;
    for (auto &[k, v] : dic)
    {
        if (v > curr_max)
        {
            curr_max = v;
            ans = k;
        }
        else if (v == curr_max)
        {
            ans = min(k, ans);
        }
    }
    cout << ans << endl;

    return 0;
}
