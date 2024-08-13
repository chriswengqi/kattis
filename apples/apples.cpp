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

void solve()
{
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;
    vs arr(r);

    for (int i = 0; i < r; i++)
    {
        cin >> arr[i];
    }

    for (int j = 0; j < c; j++)
    {
        vi apples;
        int curr = 0;
        for (int i = r - 1; i >= 0; i--)
        {
            if (arr[i][j] == '#')
            {
                apples.pb(curr);
                curr = 0;
            }
            else if (arr[i][j] == 'a')
            {
                curr++;
            }
        }
        if (arr[0][j] != '#')
            apples.pb(curr);

        int curr_piles = 0;

        for (int i = r - 1; i >= 0; i--)
        {
            if (arr[i][j] == '#')
            {
                curr_piles++;
            }
            else if (apples[curr_piles] > 0)
            {
                arr[i][j] = 'a';
                apples[curr_piles]--;
            }
            else
            {
                arr[i][j] = '.';
            }
        }
    }

    for (string s : arr)
    {
        cout << s << endl;
    }

    return 0;
}
