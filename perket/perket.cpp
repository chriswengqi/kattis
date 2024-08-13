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

vector<vector<pii>> getSubsets(vpii nums)
{
    vector<vector<pii>> subsets{vpii()};

    for (const pii num : nums)
    {
        vector<vector<pii>> ssCopies = subsets;

        for (auto &&subsetCopy : ssCopies)
        {
            subsetCopy.push_back(num);
            subsets.push_back(subsetCopy);
        }
    }

    return subsets;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vpii arr;
    for (int i = 0; i < n; i++)
    {
        int s, b;
        cin >> s >> b;
        arr.pb({s, b});
    }

    vector<vector<pii>> subsets = getSubsets(arr);

    int ans = 2e9;

    for (vpii v : subsets)
    {
        if (v.size() == 0)
            continue;
        int sour = 1;
        int bitter = 0;

        for (pii p : v)
        {
            sour *= p.first;
            bitter += p.second;
        }

        ans = min(ans, abs(sour - bitter));
    }

    cout << ans << endl;

    return 0;
}
