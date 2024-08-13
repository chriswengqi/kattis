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
int MOD = 1000000007;

int power(int base, int power)
{
    int curr = 1;
    while (power > 0)
    {
        if (power & 1)
        {
            curr *= base;
            curr %= MOD;
        }
        base = base * base;
        base %= MOD;
        power >>= 1;
    }
    return curr % MOD;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, q;
    cin >> v >> e >> q;
    int x, y;
    vvi adj(4000, vi(4000, 0));
    for (int i = 0; i < e; i++)
    {
        int uu, vv;
        cin >> uu >> vv;
        adj[uu][vv] = 1;
    }
    vi mod(4000);
    int curr = 1;
    // Preprocess mods
    for (int i = 0; i < 4000; i++)
    {
        mod[i] = curr;
        curr *= 7;
        curr %= MOD;
    }
    int flipped = 0;
    int transposed = 0;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        switch (t)
        {
        case 1:
            for (int i = 0; i < v; i++)
            {
                adj[i][v] = adj[v][i] = flipped;
            }
            v++;
            break;
        case 2:
            cin >> x >> y;
            if (!transposed)
                adj[x][y] ^= 1;
            else
                adj[y][x] ^= 1;
            break;
        case 3: // same for both transposed and non-transposed
            cin >> x;

            for (int i = 0; i < v; i++)
                adj[i][x] = adj[x][i] = flipped;
            break;
        case 4:
            cin >> x >> y;
            if (!transposed)
                adj[x][y] ^= 1;
            else
                adj[y][x] ^= 1;
            break;
        case 5:
            transposed ^= 1;
            break;
        case 6:
            flipped ^= 1;
            break;

        default:
            break;
        }

        // for (int i = 0; i < v; i++)
        // {
        //     for (int j = 0; j < v; j++)
        //     {
        //         int curr;
        //         if (flipped)
        //             curr = adj[i][j] ^ 1;
        //         else
        //             curr = adj[i][j];
        //         cout << curr << " ";
        //     }
        //     cout << endl;
        // }
    }
    cout << v << endl;
    if (transposed == 0)
    {
        for (int i = 0; i < v; i++)
        {
            int curr = 0;
            int total = 0;
            for (int j = 0; j < v; j++)
            {
                if (i != j)
                {
                    if (flipped ^ adj[i][j])
                    {
                        total += (j * mod[curr]) % MOD;
                        total %= MOD;
                    }
                    curr += adj[i][j] ^ flipped;
                }
            }

            cout << curr << " " << total << endl;
        }
    }
    else
    {
        for (int j = 0; j < v; j++)
        {
            int curr = 0;
            int total = 0;
            for (int i = 0; i < v; i++)
            {
                if (i != j)
                {
                    if (flipped ^ adj[i][j])
                    {
                        total += (i * mod[curr]) % MOD;
                        total %= MOD;
                    }
                    curr += adj[i][j] ^ flipped;
                }
            }

            cout << curr << " " << total << endl;
        }
    }

    return 0;
}