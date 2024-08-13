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

vvi getSubsets(vi nums)
{
    vvi subsets{vi()};

    for (const int num : nums)
    {
        vvi ssCopies = subsets;

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

    vi arr1;
    vi arr2;
    for (int i = 0; i < n / 2; i++)
    {
        string s;
        cin >> s;
        int ans = 0;
        for (int j = 0; j < s.size(); j++)
        {
            ans = ans | (1 << int(s[j] - 'a'));
        }

        arr1.pb(ans);
    }

    for (int i = n / 2; i < n; i++)
    {
        string s;
        cin >> s;
        int ans = 0;
        for (int j = 0; j < s.size(); j++)
        {
            ans = ans | (1 << int(s[j] - 'a'));
        }

        arr2.pb(ans);
    }

    int op = 0;

    vvi subsets1 = getSubsets(arr1);
    vvi subsets2 = getSubsets(arr2);
    int bitmask = (1 << 26) - 1;
    unordered_map<int, int> ss1;
    unordered_map<int, int> ss2;

    for (vi subset : subsets1)
    {
        int ans = 0;
        for (int a : subset)
        {
            ans |= a;
        }
        if (!ss1.count(ans))
            ss1[ans] = 0;
        ss1[ans]++;
    }
    for (vi subset : subsets2)
    {
        int ans = 0;
        for (int a : subset)
        {
            ans |= a;
        }
        if (!ss2.count(ans))
            ss2[ans] = 0;
        ss2[ans]++;
    }

    for (auto &[k1, v1] : ss1)
    {
        for (auto &[k2, v2] : ss2)
        {
            if ((k1 | k2) == bitmask)
            {
                op += v1 * v2;
            }
        }
    }

    cout << op << endl;

    return 0;
}
