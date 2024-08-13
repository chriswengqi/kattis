#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
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
    cin >> n;

    while (n != 0)
    {
        unordered_map<int, int> ans;
        int bags = 0;
        for (int i = 0; i < n; i++)
        {
            int s;
            cin >> s;
            if (!ans.count(s))
            {
                ans[s] = 0;
            }
            ans[s]++;
            bags = max(bags, ans[s]);
        }

        cout << bags << endl;
        bool flag = true;
        for (int i = 0; i < bags; i++)
        {
            for (auto &[k, v] : ans)
            {
                if (v == 0)
                {
                    continue;
                }
                flag = false;
                cout << k << " ";
                v--;
            }

            cout << endl;
            if (flag)
                break;
        }

        cin >> n;
    }

    return 0;
}
