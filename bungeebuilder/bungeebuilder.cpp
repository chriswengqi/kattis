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
    int minn = -1;
    int prev = -1;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        if (i == 0)
        {
            prev = s;
            minn = s;
        }
        else
        {
            if (s < minn)
            {
                minn = s;
            }
            else if (s >= prev)
            {
                ans = max(prev - minn, ans);
                prev = s;
                minn = s;
            }
            else if (s < prev)
            {
                ans = max(s - minn, ans);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
