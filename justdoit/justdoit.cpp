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

void debug(int a)
{
    cout << a << endl;
}

void debug(vi &arr)
{
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}

void debug(vvi &grid)
{
    for (vi row : grid)
    {
        for (int a : row)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}

void debug(string s)
{
    cout << s << endl;
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vpii min_stack;
    vpii max_stack;

    int ans = 0;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr = arr[i] * arr[i];
        if (i == 0)
        {
            min_stack.pb({arr[i], 0});
            max_stack.pb({arr[i], 0});
        }
        else
        {
            while (min_stack.size() > 0 && arr[i] < min_stack.back().first)
            {
                min_stack.pop_back();
            }
            min_stack.pb({arr[i], i});

            while (max_stack.size() > 0 && arr[i] > max_stack.back().first)
            {
                max_stack.pop_back();
            }

            max_stack.pb({arr[i], i});
        }

        for (auto [k, v] : min_stack)
        {
            cout << "(" << k << ", " << v << ") ";
        }
        cout << endl;

        for (auto [k, v] : max_stack)
        {
            cout << "(" << k << ", " << v << ") ";
        }
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    // cin >> TC;
    TC = 1;

    while (TC--)
    {
        solve();
    }

    return 0;
}