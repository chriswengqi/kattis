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

    string s;
    cin >> s;
    int n = s.size();

    string ans = s;

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string curr = s;
            reverse(curr.begin(), curr.begin() + i);
            reverse(curr.begin() + i, curr.begin() + j);
            reverse(curr.begin() + j, curr.end());
            if (curr < ans)
            {
                ans = curr;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
