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

    int n;

    while (cin >> n)
    {
        vi arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vi ans;

        for (int i = 1; i < n; i++)
        {
            ans.pb(abs(arr[i] - arr[i - 1]));
        }

        sort(ans.begin(), ans.end());
        bool flag = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (ans[i] != i + 1)
            {
                cout << "Not jolly" << endl;
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << "Jolly" << endl;
        }
    }
    return 0;
}
