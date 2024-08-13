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

    int n, l, p;
    cin >> n >> l >> p;

    vi arr(n);
    int door = l / 2;
    int max_dist = 0;

    for (int i = 0; i < p; i++)
    {
        int x;
        cin >> x;
        int car = min(x / l, n - 1);

        arr[car]++;
        max_dist = max(max_dist, abs(car * l + door - x));
    }

    cout << max_dist << endl;
    cout << *max_element(arr.begin(), arr.end()) << endl;

    return 0;
}
