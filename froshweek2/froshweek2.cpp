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

    int n, m;
    cin >> n >> m;

    vi tasks(n);
    vi times(m);

    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> times[i];
    }

    sort(tasks.begin(), tasks.end());
    sort(times.begin(), times.end());

    int ans = 0;
    int ptr = 0;
    for (int i = 0; i < n; i++)
    {
        while (ptr < m && tasks[i] > times[ptr])
        {
            ptr++;
        }
        if (ptr == m)
            break;
        ans++;
        ptr++;
    }

    cout << ans << endl;

    return 0;
}
