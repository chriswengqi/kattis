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

    int s, n, m;
    cin >> s >> n >> m;
    vi arr(s);

    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }

    vi li(s, 1);
    vi ld(s, 1);
    vi ri(s, 1);
    vi rd(s, 1);

    for (int i = 1; i < s; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            li[i] = li[i - 1] + 1;
        }
        if (arr[i] < arr[i - 1])
        {
            ld[i] = ld[i - 1] + 1;
        }
    }

    for (int i = s - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            ri[i] = ri[i + 1] + 1;
        }
        if (arr[i] < arr[i + 1])
        {
            rd[i] = rd[i + 1] + 1;
        }
    }

    int peaks = 0;
    int valleys = 0;

    for (int i = 0; i < s; i++)
    {
        if (min(li[i], ri[i]) >= n)
            peaks++;
        if (min(ld[i], rd[i]) >= m)
            valleys++;
    }

    cout << peaks << " " << valleys << endl;

    return 0;
}
