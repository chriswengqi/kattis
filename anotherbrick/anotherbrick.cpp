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

void solve()
{
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, n;
    cin >> h >> w >> n;

    vi arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l = 0;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += arr[i];
        if (curr > w)
        {
            cout << "NO" << endl;
            return 0;
        }
        else if (curr == w)
        {
            curr = 0;
            l++;
            if (l == h)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
