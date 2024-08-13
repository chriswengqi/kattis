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

    int c, k;
    cin >> c >> k;

    int p = pow(10, k);
    int up = (c / p) * p;
    int down = (c / p + 1) * p;

    if (abs(up - c) < abs(down - c))
    {
        cout << up << endl;
    }
    else
    {
        cout << down << endl;
    }

    return 0;
}
