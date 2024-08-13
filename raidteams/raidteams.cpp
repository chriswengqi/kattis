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

    int n;
    cin >> n;

    set<pair<int, string>> f;
    set<pair<int, string>> d;
    set<pair<int, string>> t;
    unordered_map<string, bool> chosen;

    for (int i = 0; i < n; i++)
    {
        string s;
        int a, b, c;
        cin >> s >> a >> b >> c;
        chosen[s] = false;
        f.insert({-a, s});
        d.insert({-b, s});
        t.insert({-c, s});
    }

    for (int i = 0; i < n / 3; i++)
    {
        vs team(3);
        while (chosen[f.begin()->second])
        {
            f.erase(f.begin());
        }
        team[0] = f.begin()->second;
        chosen[f.begin()->second] = true;
        f.erase(f.begin());

        while (chosen[d.begin()->second])
        {
            d.erase(d.begin());
        }
        team[1] = d.begin()->second;
        chosen[d.begin()->second] = true;
        d.erase(d.begin());

        while (chosen[t.begin()->second])
        {
            t.erase(t.begin());
        }
        team[2] = t.begin()->second;
        chosen[t.begin()->second] = true;
        t.erase(t.begin());

        sort(team.begin(), team.end());
        for (string s : team)
        {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
