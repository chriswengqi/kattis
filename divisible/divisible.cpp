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
    int n, k;
    cin >> k >> n;
    vi arr(n);
    unordered_map<int, int> dic;
    dic[0] = 1;
    int total = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
        if (dic.count(total % k))
        {
            ans += dic[total % k];
            dic[total % k]++;
        }
        else
        {
            dic[total % k] = 1;
        }
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
