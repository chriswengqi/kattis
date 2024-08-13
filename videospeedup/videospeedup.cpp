#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<double> vd;
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
    double p, k;
    cin >> n >> p >> k;

    vd arr(n);
    for (double &a : arr)
    {
        cin >> a;
    }

    double speed = 1;
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ans = arr[i];
        }
        else
        {
            ans += (arr[i] - arr[i - 1]) * speed;
        }
        speed += p / 100;
    }
    ans += (k - arr.back()) * speed;

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
