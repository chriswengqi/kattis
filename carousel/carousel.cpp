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

    int n, m;
    cin >> n >> m;

    while (n != 0 && m != 0)
    {
        double best = 1e9;
        int best_a = 0;
        int best_b = 0;

        for (int i = 0; i < n; i++)
        {
            double a, b;
            cin >> a >> b;
            if (a <= m)
            {
                if (b / a < best)
                {
                    best = b / a;
                    best_a = (int)a;
                    best_b = (int)b;
                }
                else if (b / a == best && b > best_b)
                {
                    best_a = (int)a;
                    best_b = (int)b;
                }
            }
        }

        if (best == 1e9)
        {
            cout << "No suitable tickets offered" << endl;
        }
        else
        {
            cout << "Buy " << best_a << " tickets for $" << best_b << endl;
        }

        cin >> n >> m;
    }

    return 0;
}
