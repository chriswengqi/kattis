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

    string s;
    while (getline(cin, s))
    {
        unordered_map<char, pii> dic;

        vs keyboard = {"`1234567890-=", "QWERTYUIOP[]\\",
                       "ASDFGHJKL;'",
                       "ZXCVBNM,./"};

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < keyboard[i].size(); j++)
            {
                dic[keyboard[i][j]] = {i, j};
            }
        }

        for (char c : s)
        {
            if (c != ' ')
            {
                pii curr = dic[c];
                cout << keyboard[curr.first][curr.second - 1];
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
