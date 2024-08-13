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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vvi diff;
    diff.pb(arr);

    while (true)
    {
        vi curr;
        vi prev = diff.back();
        for (int i = 0; i < prev.size() - 1; i++)
        {
            curr.pb(prev[i + 1] - prev[i]);
        }
        bool flag = true;
        for (int i = 1; i < curr.size() && flag; i++)
        {
            if (curr[i] != curr[i - 1])
            {
                flag = false;
            }
        }
        diff.pb(curr);
        if (flag || curr.size() == 1)
        {
            break;
        }
    }

    int ans = 0;

    for (int i = 0; i < diff.size(); i++)
    {
        ans += diff[i].back();
    }

    cout << diff.size() - 1 << " " << ans << endl;

    return 0;
}
