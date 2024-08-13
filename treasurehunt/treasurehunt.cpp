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

    int R, C;
    cin >> R >> C;
    vector<string> grid(R);

    for (int i = 0; i < R; i++)
    {
        cin >> grid[i];
    }

    int x = 0;
    int y = 0;
    int steps = 0;
    set<pii> hm;
    hm.insert(mp(x, y));

    while (true)
    {
        char curr = grid[x][y];
        if (curr == 'E')
            y++;
        if (curr == 'W')
            y--;
        if (curr == 'N')
            x--;
        if (curr == 'S')
            x++;
        if (curr == 'T')
        {
            cout << steps << endl;
            return 0;
        }
        steps++;
        if (hm.find(mp(x, y)) != hm.end())
        {
            cout << "Lost" << endl;
            return 0;
        }
        hm.insert(mp(x, y));

        if (x < 0 || x == R || y < 0 || y == C)
        {
            cout << "Out" << endl;
            return 0;
        }
    }

    return 0;
}
