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

vvi getSubsets(vi arr)
{
    vvi subsets{vi()};

    for (int a : arr)
    {
        vvi ss = subsets;

        for (auto &&ssc : ss)
        {
            ssc.push_back(a);
            subsets.push_back(ssc);
        }
    }

    return subsets;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    vi stack;
    vpii brackets;
    vi arr;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            stack.pb(i);
        }
        else if (s[i] == ')')
        {
            int s = stack.back();
            brackets.pb({s, i});
            stack.pop_back();
        }
    }

    for (int i = 0; i < brackets.size(); i++)
    {
        arr.pb(i);
    }

    vvi subsets = getSubsets(arr);
    set<string> ans;

    for (vi subset : subsets)
    {
        if (subset.size() == 0)
            continue;
        vc vec(s.begin(), s.end());
        for (int a : subset)
        {
            vec[brackets[a].first] = ' ';
            vec[brackets[a].second] = ' ';
        }

        vc new_vc;

        for (char a : vec)
        {
            if (a != ' ')
            {
                new_vc.pb(a);
            }
        }

        string st(new_vc.begin(), new_vc.end());

        ans.insert(st);
    }

    for (string s : ans)
    {
        cout << s << endl;
    }

    return 0;
}
