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

void solve()
{
    string s;
    getline(cin, s);
    list<char> lst;
    auto it = lst.begin();
    for (char c : s)
    {
        if (c == ']')
        {
            it = lst.end();
        }
        else if (c == '[')
        {
            it = lst.begin();
        }
        else if (c == '<')
        {
            if (it != lst.begin())
            {
                it--;
                it = lst.erase(it);
            }
        }
        else
        {
            lst.insert(it, c);
        }
    }

    for (char c : lst)
    {
        cout << c;
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    string _;

    getline(cin, _);

    while (TC--)
    {
        solve();
    }

    return 0;
}
