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

void debug(vi arr)
{
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}

void debug(vs arr)
{
    for (string a : arr)
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
    vvi adj(10, vi());

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vs names(10);
    vs countries(10);
    vs leagues(10);
    vs clubs(10);
    vi perms(10);
    for (int i = 0; i < 10; i++)
    {
        perms[i] = i;
        cin >> names[i] >> countries[i] >> leagues[i] >> clubs[i];
    }

    do
    {
        bool can = true;
        for (int i = 0; i < 10 && can; i++)
        {
            int uu = perms[i];
            int synergy = 0;
            for (int v : adj[i])
            {

                int vv = perms[v];
                synergy += (countries[uu] == countries[vv]) + (leagues[uu] == leagues[vv]) + (clubs[uu] == clubs[vv]);
                if (synergy >= adj[i].size())
                    break;
            }

            // debug(vi{uu, (ll)adj[uu].size(), synergy});
            if (synergy < adj[i].size())
            {
                can = false;
            }
        }

        if (can)
        {
            cout << "yes" << endl;
            return 0;
        }
    } while (next_permutation(perms.begin(), perms.end()));

    cout << "no" << endl;

    return 0;
}