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
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool flag = false;

    for (int i = 0; i < d / a + 1; i++)
    {
        for (int j = 0; j < d / b + 1; j++)
        {
            for (int k = 0; k < d / c + 1; k++)
            {
                if (a * i + b * j + c * k == d)
                {
                    flag = true;
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }

    if (!flag)
    {
        cout << "impossible" << endl;
    }

    return 0;
}
