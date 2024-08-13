#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<double> vd;
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

    int n, m, k;
    cin >> n >> m >> k;

    vi land(n);
    vd house(m + k);
    for (int i = 0; i < n; i++)
    {
        cin >> land[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> house[i];
    }

    for (int i = m; i < m + k; i++)
    {
        double s;
        cin >> s;
        house[i] = s * sqrt(2) / 2;
    }

    sort(land.begin(), land.end());
    sort(house.begin(), house.end());

    int i = 0;
    int j = 0;
    int ans = 0;
    while (i < n && j < m + k)
    {
        if (land[i] > house[j])
        {
            i++;
            j++;
            ans++;
        }
        else
        {
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}
