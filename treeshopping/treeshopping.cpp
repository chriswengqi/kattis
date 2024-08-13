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

    int n, k;
    cin >> n >> k;

    vi arr(n);

    for (auto &a : arr)
    {
        cin >> a;
    }

    priority_queue<pii> max_heap;
    priority_queue<pii, vector<pii>, greater<pii>> min_heap;

    for (int i = 0; i < k; i++)
    {
        max_heap.push({arr[i], i});
        min_heap.push({arr[i], i});
    }

    int left = 0;
    int right = k - 1;

    int ans = 1e9;

    while (right < n)
    {
        while (max_heap.top().second < left)
        {
            max_heap.pop();
        }
        while (min_heap.top().second < left)
        {
            min_heap.pop();
        }
        // cout << max_heap.top().first << " " << min_heap.top().first << endl;
        ans = min(max_heap.top().first - min_heap.top().first, ans);
        left++;
        right++;
        max_heap.push({arr[right], right});
        min_heap.push({arr[right], right});
    }

    cout << ans << endl;

    return 0;
}
