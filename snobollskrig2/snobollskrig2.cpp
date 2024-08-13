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

    int n, m;
    cin >> n >> m;
    vi swe(n);
    vi fin(m);

    for (int i = 0; i < n; i++)
    {
        cin >> swe[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> fin[i];
    }

    int i = 0;
    int j = 0;
    int ans = 0;
    int turn = 0; // 0 is swe, 1 is fin
    while (i < n && j < m)
    {
        if (swe[i] < fin[j])
        {
            turn = 1;
            i++;
            // swe start fight, fin throw back
            while (true)
            {
                if (turn == 1 && fin[j] > swe[i])
                {
                    ans++;
                    turn ^= 1;
                }
            }
        }
    }

    return 0;
}
