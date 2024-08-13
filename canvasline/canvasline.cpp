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
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
#define debug1(a)                           \
    for (int i = 0; i <= a.size() - 1; i++) \
    cout << a[i] << (i == a.size() - 1 ? '\n' : ' ')
#define debug2(a)                                  \
    for (int i = 0; i <= a.size() - 1; i++)        \
        for (int j = 0; j <= a[0].size() - 1; j++) \
    cout << a[i][j] << (j == a[0].size() - 1 ? '\n' : ' ')

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi left(n);
    vi right(n);
    vi pegs(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> left[i] >> right[i];
    }

    int q;
    uset<int> curr;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int s;
        cin >> s;
        curr.insert(s);
        auto it = lower_bound(right.begin(), right.end(), s);

        if (it == right.end())
            continue;
        else if (it == right.begin() && s < left[0])
            continue;
        else
        {

            int idx = it - right.begin();
            if (s == left[idx + 1])
            {
                pegs[idx + 1]++;
            }
            if (s >= left[idx] && s <= right[idx])
            {
                pegs[idx]++;
            }
        }
    }
    // debug1(pegs);
    vi ans;
    for (int i = 0; i < n - 1; i++)
    {
        if (pegs[i] > 2)
        {
            cout << "impossible" << endl;
            return 0;
        }
        if (right[i] == left[i + 1] && !curr.count(right[i]))
        {
            if (pegs[i] < 2 && pegs[i + 1] < 2)
            {
                ans.pb(right[i]);
                pegs[i]++;
                pegs[i + 1]++;
            }
        }
        while (pegs[i] < 2)
        {
            int mid = (left[i] + right[i]) / 2;
            while (curr.count(mid))
                mid++;
            ans.pb(mid);
            curr.insert(mid);
            pegs[i]++;
        }
    }
    if (pegs[n - 1] > 2)
    {
        cout << "impossible" << endl;
        return 0;
    }
    while (pegs[n - 1] < 2)
    {
        int mid = (left[n - 1] + right[n - 1]) / 2;
        while (curr.count(mid))
            mid++;
        ans.pb(mid);
        curr.insert(mid);
        pegs[n - 1]++;
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}