#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
typedef tuple<int, int, int> iii;

#define pb push_back
#define em emplace
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define INF 1e9
#define LLINF 4e18
#define umap unordered_map
#define uset unordered_set

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    vi lb(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> lb[i];
    }

    int l = *min_element(arr.begin(), arr.end());
    int r = *max_element(arr.begin(), arr.end());

    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= mid)
            {
                total += (arr[i] - max(lb[i], mid));
            }
            else
            {
                total -= (mid - arr[i]);
            }
        }

        if (total == 0)
        {
            cout << mid << endl;
            return;
        }
        else if (total > 0)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= r)
        {
            total += (arr[i] - max(lb[i], r));
        }
        else
        {
            total -= (r - arr[i]);
        }
    }

    if (total >= 0)
        cout << r << endl;
    else
        cout << l << endl;
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