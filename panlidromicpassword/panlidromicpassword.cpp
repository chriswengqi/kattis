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

    set<int> s;
    for (int i = 100; i <= 999; i++)
    {
        // reverse
        int x = i;
        int y = 0;
        while (x > 0)
        {
            y = y * 10 + x % 10;
            x = x / 10;
        }
        s.insert(i * 1000 + y);
    }
    s.insert(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        auto it = s.lower_bound(t);
        auto it2 = it;
        it2--;
        if (abs(*it - t) >= abs(*it2 - t))
        {
            cout << *it2 << endl;
        }
        else
        {
            cout << *it << endl;
        }
    }

    return 0;
}
