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

    vi idp(n, 1);
    vi ddp(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                idp[i] = max(idp[i], idp[j] + 1);
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[i])
                ddp[i] = max(ddp[i], ddp[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, idp[i] + ddp[i] - 1);
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
