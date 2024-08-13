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

vi primeFactors(int n)
{
    unordered_set<int> ans;
    while (n % 2 == 0)
    {
        ans.insert(2);
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            ans.insert(i);
            n = n / i;
        }
    }
    if (n > 2)
        ans.insert(n);

    return vi(ans.begin(), ans.end());
}

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

    while (n != 0)
    {
        vi ans = primeFactors(n);
        vvi subsets = getSubsets(ans);

        int output = n;

        for (auto subset : subsets)
        {
            if (subset.size() == 0)
            {
                continue;
            }
            int multiple = 1;
            for (int a : subset)
            {
                multiple *= a;
            }
            // cout << multiple << endl;
            if (subset.size() % 2 == 1)
            {
                output -= n / multiple;
            }
            else
            {
                output += n / multiple;
            }
        }

        cout << output << endl;
        cin >> n;
    }

    return 0;
}
