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

vs split(string &s, char delim)
{
    vs result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim))
    {
        result.push_back(item);
    }

    return result;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n != 0)
    {
        map<string, vs> m;
        for (int i = 0; i < n; i++)
        {
            string s;
            getline(cin, s);
            cout << s << endl;
            vs v = split(s, ' ');

            for (int i = 1; i < v.size(); i++)
            {
                m[v[i]].pb(v[0]);
            }
        }

        for (auto &[k, v] : m)
        {
            sort(v.begin(), v.end());
            cout << k << " ";
            for (auto &s : v)
            {
                cout << s << " ";
            }
            cout << endl;
        }

        cout << endl;
        cin >> n;
    }

    return 0;
}
