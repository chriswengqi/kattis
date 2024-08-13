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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    if (n <= 25)
    {
        s = "aa";
        s.back() = (char)('a' + n);
    }
    else
    {
        int chars = (n + 24) / 25 + 1;
        for (int i = 0; i < chars; i++)
        {
            s.pb(i % 2 == 0 ? 'a' : 'z');
        }
        int ttl = (chars - 1) * 25;
        s[1] = char(s[1] - (ttl - n) / 2);
        if ((ttl - n) % 2 == 1)
        {
            if (chars % 2 == 1)
                s.back() = char(s.back() + 1);
            else
                s.back() = char(s.back() - 1);
        }
    }
    cout << s << endl;

    return 0;
}
