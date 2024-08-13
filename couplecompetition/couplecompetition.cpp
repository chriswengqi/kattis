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
    vpii lset; // {number, -ind} larger index more important
    vpii rset; // {number, ind} smaller index more important
    vi ldp(n, 0);
    ldp[0] = 0;
    vi rdp(n, 0);
    rdp[n - 1] = 0;
    vi nearest_l(n, 0);
    vi nearest_r(n, 0);

    for (int i = 0; i < n; i++)
    {
        while (lset.size() > 0 && lset.back().first <= arr[i])
        {
            lset.pop_back();
        }
        if (lset.size() > 0)
        {
            int ind = lset.back().second;
            ldp[i] = ldp[ind] + 1;
            nearest_l[i] = ind;
        }
        else
        {
            nearest_l[i] = i;
        }
        lset.pb({arr[i], i});
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (rset.size() > 0 && rset.back().first <= arr[i])
        {
            rset.pop_back();
        }
        if (rset.size() != 0)
        {
            int ind = rset.back().second;
            rdp[i] = rdp[ind] + 1;
            nearest_r[i] = ind;
        }
        else
        {
            nearest_r[i] = i;
        }
        rset.pb({arr[i], i});
    }

    debug(ldp);
    debug(nearest_l);

    debug(rdp);
    debug(nearest_r);

    int l = 0;
    int r = n - 1;
    int turn = 0;
    while (l < r)
    {
        if (!turn)
        {
            if (nearest_r[l] != l)
            {
                ldp[l] = r;
            }
        }
        else
        {
        }
        turn ^= 1;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     if (ldp[i] == rdp[i])
    //         cout << ldp[i] << " ";
    //     else if (ldp[i] == 0)
    //         cout << rdp[i] << " ";
    //     else if (rdp[i] == 0)
    //         cout << ldp[i] << " ";
    //     else
    //         cout << min(ldp[i], rdp[i]) << " ";
    // }
    // cout << endl;

    return 0;
}