// UNSOLVED

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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vs grid(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> grid[i];
        }
        int x = 0;
        int o = 0;

        for (int k = 0; k < 3; k++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[k][j] == 'X')
                    x++;
                if (grid[k][j] == 'O')
                    o++;
            }
        }

        if (x == o + 1 || x == o)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}
