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

    string s, t;
    cin >> s >> t;
    int dp = s.size() - t.size();

    vc arr(s.begin(), s.end());
    vc ans;

    if (dp < 0)
    {
        ans.pb('0');
        ans.pb('.');
        while (dp < -1)
        {
            ans.pb('0');
            dp++;
        }
        for (char s : arr)
        {
            ans.pb(s);
        }
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            ans.pb(s[i]);
            if (i == dp)
            {
                ans.pb('.');
            }
        }
    }

    while (ans.back() == '0')
    {
        ans.pop_back();
    }
    if (ans.back() == '.')
    {
        ans.pop_back();
    }

    for (char c : ans)
    {
        cout << c;
    }
    cout << endl;

    return 0;
}
