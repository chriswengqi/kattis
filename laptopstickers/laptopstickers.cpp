#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, h, k;
    cin >> l >> h >> k;

    vector<vector<char>> grid(h, vector<char>(l, '_'));

    for (int i = 0; i < k; i++)
    {
        int p, q, x, y;
        cin >> p >> q >> x >> y;
        for (int a = 0; a < q; a++)
        {
            for (int b = 0; b < p; b++)
            {
                if (y + a < h && x + b < l)
                    grid[y + a][x + b] = (char)(i + 'a');
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
