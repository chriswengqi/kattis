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
    int k;
    cin >> k;
    vector<uset<string>> arr(n, uset<string>());
    for (int i = 0; i < k; i++)
    {
        int s;
        string t;
        cin >> s >> t;
        arr[s].insert(t);
    }
    int l;
    cin >> l;
    vs items(l);
    for (int i = 0; i < l; i++)
    {
        cin >> items[i];
    }

    // forward
    int curr = 0;
    int shop = 0;
    vi forward;
    while (shop < n && curr < l)
    {
        if (arr[shop].count(items[curr]))
        {
            forward.pb(shop);
            curr++;
        }
        else
        {
            shop++;
        }
        // debug(shop);
        // debug(curr);
    }
    if (forward.size() != l)
    {
        cout << "impossible" << endl;
        return 0;
    }

    // debug1(forward);

    vi backwards;
    curr = l - 1;
    shop = n - 1;
    while (curr >= 0 && shop >= 0)
    {
        if (arr[shop].count(items[curr]))
        {
            backwards.pb(shop);
            curr--;
        }
        else
            shop--;
    }

    reverse(backwards.begin(), backwards.end());

    if (forward == backwards)
    {
        cout << "unique" << endl;
    }
    else
    {
        cout << "ambiguous" << endl;
    }

    return 0;
}