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
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vvi arr(n, vi(366, 0));

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            int N, D;
            cin >> N >> D;
            arr[i][D] += N;
        }
    }
    vi curr(n, 0);
    for (int i = 1; i < 366; i++)
    {
        bool flag = false;
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] != 0)
            {
                flag = true;
                curr[j] = arr[j][i];
            }
        }

        if (flag)
        {
            int ans = 0;
            for (int a : curr)
                ans += a;
            cout << ans << " ";
        }
    }

    cout << endl;

    return 0;
}
