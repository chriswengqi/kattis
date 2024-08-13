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

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        unordered_map<char, int> dic;
        for (char c : s)
        {
            if (!dic.count(c))
                dic[c] = 0;
            dic[c]++;
        }
        int odds = 0;
        for (auto &[k, v] : dic)
        {
            if (v % 2 == 1)
            {
                odds++;
            }
        }

        if (odds > 1)
        {
            cout << "Impossible" << endl;
            continue;
        }

        int left = 0;
        int right = s.size() - 1;
        int ans = 0;

        while (left < right)
        {
            int l = left;
            int r = right;
            while (s[l] != s[r])
                r--;
            if (l == r)
            {
                swap(s[r], s[r + 1]);
                ans++;
                continue;
            }
            else
            {
                while (r < right)
                {
                    swap(s[r], s[r + 1]);
                    ans++;
                    r++;
                }
            }
            left++, right--;
        }

        cout << ans << endl;
    }
    return 0;
}
