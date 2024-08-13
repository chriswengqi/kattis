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

    int a, b;
    cin >> a >> b;

    while (a != 0 || b != 0)
    {
        int ans = 0;
        int carry = 0;
        while (a != 0 || b != 0)
        {
            int curr = a % 10 + b % 10 + carry;
            if (curr >= 10)
            {
                ans++;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            a /= 10;
            b /= 10;
        }
        if (ans == 0)
        {
            cout << "No carry operation." << endl;
        }
        else if (ans == 1)
        {
            cout << "1 carry operation." << endl;
        }
        else
        {
            cout << ans << " carry operations." << endl;
        }
        cin >> a >> b;
    }

    return 0;
}
