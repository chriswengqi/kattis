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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vs arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_set<string> dic;
    int bit = 1;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dic.insert(arr[i]);
            continue;
        }

        if (arr[i][0] != arr[i - 1].back() || dic.count(arr[i]))
        {
            char loser = (bit == 0) ? '1' : '2';
            cout << "Player " << loser << " lost";
            return 0;
        }

        dic.insert(arr[i]);

        bit ^= 1;
    }

    cout << "Fair Game" << endl;
    return 0;
}
