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
    cin >> n;
    string s;
    getline(cin, s);
    int curr = 1;
    for (char c : s)
    {
        if (c == 'L')
        {
            curr *= 2;
        }
        else if (c == 'R')
        {
            curr = curr * 2 + 1;
        }
    }

    int ans = pow(2, n + 1) - curr;

    cout << ans << endl;

    return 0;
}
