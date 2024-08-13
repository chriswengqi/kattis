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

    int c, n, a;
    cin >> c >> n >> a;
    int ans = 0;
    umap<int, int> dic;
    uset<int> s;
    for (int i = 0; i < a; i++)
    {
        int curr;
        cin >> curr;
        if (!s.count(curr))
        {
            ans++;
            s.insert(curr);
            if (s.size() > c)
            {
                int rem = dic[i - c];
                dic.erase(i - c);
                s.erase(rem);
            }
        }
        dic[i] = curr;
    }

    cout << ans << endl;

    return 0;
}