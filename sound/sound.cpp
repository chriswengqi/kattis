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

    int n, m, c;
    cin >> n >> m >> c;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    priority_queue<pii> max_heap;
    priority_queue<pii, vector<pii>, greater<pii>> min_heap;

    for (int i = 0; i < m; i++)
    {
        max_heap.push({arr[i], i});
        min_heap.push({arr[i], i});
    }

    int left = 0;
    int right = m - 1;

    vi ans;

    while (right < n)
    {
        while (min_heap.top().second < left)
        {
            min_heap.pop();
        }
        while (max_heap.top().second < left)
        {
            max_heap.pop();
        }

        if (max_heap.top().first - min_heap.top().first <= c)
        {

            ans.pb(left + 1);
        }

        left++;
        right++;
        if (right == n)
        {
            break;
        }
        min_heap.push({arr[right], right});
        max_heap.push({arr[right], right});
    }

    if (ans.size() > 0)
    {
        for (int a : ans)
        {
            cout << a << endl;
        }
    }
    else
    {
        cout << "NONE" << endl;
    }

    return 0;
}
