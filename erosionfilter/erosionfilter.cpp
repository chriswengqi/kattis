#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef long double ld;
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
    vector<ld> arr(n);

    vector<ld> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        ld curr = 0;
        for (int j = max(0LL, i - 50); j < min(n, i + 50); j++)
        {
            int power = (1LL << abs(i - j));
            curr += arr[j] / (long double)power;
        }
        ans[i] = curr;
    }

    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(10) << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
