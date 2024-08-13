#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

void solve()
{
    int n;
    cin >> n;

    int ans = 0;

    priority_queue<int> max_heap;
    priority_queue<int, vi, greater<int>> min_heap;

    for (int i = 1; i <= n; i++)
    {
        int s;
        cin >> s;
        if (max_heap.size() == 0 || s < max_heap.top())
            max_heap.push(s);
        else
            min_heap.push(s);

        while (max_heap.size() > min_heap.size() + 1)
        {
            int curr = max_heap.top();
            max_heap.pop();
            min_heap.push(curr);
        }

        while (min_heap.size() > max_heap.size())
        {
            int curr = min_heap.top();
            min_heap.pop();
            max_heap.push(curr);
        }

        if (i % 2 == 1)
        {
            ans += max_heap.top();
        }
        else
        {
            ans += (max_heap.top() + min_heap.top()) / 2;
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        solve();
    }

    return 0;
}
