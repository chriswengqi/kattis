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
    vi A(n);

    for (auto &a : A)
    {
        cin >> a;
    }

    sort(A.rbegin(), A.rend());

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 3 != 2)
        {
            ans += A[i];
        }
    }

    cout << ans << endl;

    return 0;
}
