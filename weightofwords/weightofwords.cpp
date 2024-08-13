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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, w;
    cin >> l >> w;

    if (w < l || w > 26 * l)
    {
        cout << "impossible" << endl;
        return 0;
    }

    int offset = w / l;
    int plus = w % l;

    for (int i = 0; i < l; i++)
    {
        cout << (char)('a' + offset + (plus > 0 ? 1 : 0) - 1);
        plus--;
    }
    cout << endl;

    return 0;
}
