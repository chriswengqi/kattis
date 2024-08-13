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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l, r;
    cin >> l >> r;
    sort(arr.begin(), arr.end());

    int best = 0;
    int max_dist = 0;

    for (int i = 1; i < n; i++)
    {
        int mid = (arr[i] + arr[i - 1]) / 2;
        if (mid % 2 == 1 && mid >= l && mid <= r && abs(mid - arr[i]) > max_dist)
        {
            best = mid;
            max_dist = abs(mid - arr[i]);
        }
        else
        {
            int curr_min = 1e9;
            int lb = mid - 1;
            int rb = mid + 1;
            if (lb >= l && lb <= r && min(abs(lb - arr[i]), abs(arr[i - 1] - lb)) > max_dist)
            {
                best = lb;
                max_dist = min(abs(lb - arr[i]), abs(arr[i - 1] - lb));
            }

            if (rb >= l && rb <= r && min(abs(rb - arr[i]), abs(arr[i - 1] - rb)) > max_dist)
            {
                best = rb;
                max_dist = min(abs(rb - arr[i]), abs(arr[i - 1] - rb));
            }
        }
    }
    if (l % 2 == 0)
        l++;
    if (r % 2 == 0)
        r--;
    auto lob = lower_bound(arr.begin(), arr.end(), l);
    auto rib = lower_bound(arr.begin(), arr.end(), r);

    if (lob == arr.begin())
    {
        int dist = arr[0] - l;
        if (dist > max_dist)
        {
            max_dist = dist;
            best = l;
        }
    }
    else
    {
        int lower = lob - arr.begin() - 1;
        int higher = lob - arr.begin();
        if (min(abs(arr[lower] - l), abs(arr[higher] - l)) > max_dist)
        {
            max_dist = min(abs(arr[lower] - l), abs(arr[higher] - l));
            best = l;
        }
    }

    if (rib == arr.end())
    {
        int dist = r - arr.back();
        if (dist > max_dist)
        {
            max_dist = dist;
            best = r;
        }
    }
    else
    {
        int lower = rib - arr.begin() - 1;
        int higher = rib - arr.begin();
        if (min(abs(arr[lower] - r), abs(arr[higher] - r)) > max_dist)
        {
            max_dist = min(abs(arr[lower] - r), abs(arr[higher] - r));
            best = r;
        }
    }

    cout << best << endl;

    return 0;
}