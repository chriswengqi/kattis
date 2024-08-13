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

    string s;
    cin >> s;
    unordered_map<char, int> dic;

    vvi dp(s.size(), vi(26, 0));

    for (int i = 0; i < s.size(); i++)
    {
        dp[i][s[i] - 'a']++;
    }

    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            dp[i][j] += dp[i - 1][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (!dic.count(s[i]))
        {
            ans += dic.size();
        }
        else
        {
            int prev = dic[s[i]];
            int distinct = 0;

            for (int j = 0; j < 26; j++)
            {
                if (dp[i - 1][j] - dp[prev][j] > 0)
                    distinct++;
            }
            ans += distinct;
        }
        dic[s[i]] = i;
    }

    cout << ans << endl;

    return 0;
}
