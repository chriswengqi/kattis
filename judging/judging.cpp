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
    unordered_map<string, int> a;
    unordered_map<string, int> b;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (!a.count(s))
        {
            a[s] = 0;
        }
        a[s]++;
    }

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (!b.count(s))
        {
            b[s] = 0;
        }
        b[s]++;
    }
    int ans = 0;
    for (auto &[k, v] : a)
    {
        if (b.count(k))
        {
            ans += min(a[k], b[k]);
        }
    }

    cout << ans << endl;

    return 0;
}
