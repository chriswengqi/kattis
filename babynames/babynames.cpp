#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
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

void debug(vpii &arr)
{
    for (auto [k, v] : arr)
    {
        cout << k << " " << v << endl;
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
    vvi grid(n, vi(n, 2));
    debug(grid);
}

typedef tree<string, null_type, less<string>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

signed main()
{
    int n;
    scanf("%d", &n);

    ordered_set males;
    ordered_set females;

    while (n != 0)
    {
        if (n == 1)
        {
            char s[30];
            int g;
            scanf("%s %d", s, &g);

            if (g == 1)
            {
                males.insert(s);
            }
            else
            {
                females.insert(s);
            }
        }
        else if (n == 3)
        {
            char s[30], t[30];
            int g;
            scanf("%s %s %d", s, t, &g);

            if (g == 0)
            {
                printf("%ld\n", males.order_of_key(t) - males.order_of_key(s) + females.order_of_key(t) - females.order_of_key(s));
            }
            else if (g == 1)
            {
                printf("%ld\n", males.order_of_key(t) - males.order_of_key(s));
            }
            else
            {
                printf("%ld\n", females.order_of_key(t) - females.order_of_key(s));
            }
        }
        else
        {
            char s[30];
            scanf("%s", s);

            if (*males.lower_bound(s) == s)
            {
                males.erase(s);
            }
            else
            {
                females.erase(s);
            }
        }
        scanf("%d", &n);
    }

    return 0;
}