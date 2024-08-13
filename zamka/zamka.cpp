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

    int L, D, X;
    cin >> L >> D >> X;

    for (int i = L; i <= D; i++)
    {
        int curr = i;
        int sum = 0;
        while (curr > 0)
        {
            sum += curr % 10;
            curr = curr / 10;
        }
        if (sum == X)
        {
            cout << i << endl;
            break;
        }
    }

    for (int i = D; i >= L; i--)
    {
        int curr = i;
        int sum = 0;
        while (curr > 0)
        {
            sum += curr % 10;
            curr = curr / 10;
        }
        if (sum == X)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
