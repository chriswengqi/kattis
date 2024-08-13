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

    int n, k;
    cin >> n >> k;
    vi arr;
    int first = 0;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        if (i == k)
            first = s;
        else
            arr.pb(s);
    }
    int total = first;
    if (first > 300)
    {
        cout << 0 << " " << 0 << endl;
        return 0;
    }

    sort(arr.begin(), arr.end());

    int ans = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (first + arr[i] > 300)
        {
            break;
        }
        ans++;
        first += arr[i];
        total += first;
    }

    cout << ans << " " << total << endl;

    return 0;
}