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
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

void solve()
{
    int n;
    cin >> n;
    vi arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 1;
    int start = 0;
    unordered_map<int, int> dic;

    for (int i = 0; i < n; i++)
    {
        if (!dic.count(arr[i]))
        {
            dic[arr[i]] = i;
        }
        else
        {
            start = max(dic[arr[i]] + 1, start);
            dic[arr[i]] = i;
        }
        ans = max(i - start + 1, ans);
    }

    cout << ans << endl;
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
