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

    string first, last;
    map<string, set<string>> dic;
    unordered_map<string, int> count;

    while (cin >> first >> last)
    {
        if (!dic.count(last))
        {
            dic[last] = set<string>();
        }
        dic[last].insert(first);
        if (!count.count(first))
        {
            count[first] = 0;
        }
        count[first]++;
    }

    for (auto &[k, v] : dic)
    {
        for (auto s : v)
        {
            if (count[s] == 1)
            {
                cout << s << endl;
            }
            else
            {
                cout << s << " " << k << endl;
            }
        }
    }

    return 0;
}
