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
    int curr = 1;
    vpii arr;
    int digit = 1;
    while (arr.size() < n)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = curr; j < 2 * curr; j++)
            {
                arr.pb({j, digit});
            }
            digit++;
        }
        curr *= 2;
    }

    vi ans;
    int x = arr[n - 1].first;

    while (x != 0)
    {
        ans.pb(x % 2);
        x /= 2;
    }

    vi op;
    int output = 0;

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        op.pb(ans[i]);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0 && arr[n - 1].second % 2 == 1)
        {
            continue;
        }
        op.pb(ans[i]);
    }
    int power = 1;
    for (int i = op.size() - 1; i >= 0; i--)
    {
        output += op[i] * power;
        power *= 2;
    }

    cout << output << endl;

    return 0;
}
