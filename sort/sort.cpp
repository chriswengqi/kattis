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
typedef tuple<int, int, int> iii;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    vi arr(n);
    unordered_map<int, pii> dic;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (!dic.count(arr[i]))
        {
            dic[arr[i]] = {0, i};
        }
        dic[arr[i]].first++;
    }
    vector<iii> ans;

    for (auto &[k, v] : dic)
    {
        ans.pb({k, v.first, v.second});
    }

    sort(ans.begin(), ans.end(), [](iii a, iii b)
         {if (get<1>(a) == get<1>(b)) return get<2>(b) > get<2>(a); else return get<1>(a) > get<1>(b); });

    // for (auto &[a, b, c] : ans)
    // {
    //     cout << a << " " << b << " " << c << endl;
    // }

    for (iii a : ans)
    {
        for (int i = 0; i < get<1>(a); i++)
        {
            cout << get<0>(a) << " ";
        }
    }
    cout << endl;

    return 0;
}
