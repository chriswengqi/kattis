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

vvi dp(7, vi()); // match weakness to people

int best_ans = 8;
vvi allo;

void dfs(int curr, vi days, vvi allocation)
{
    // cout << curr << " ";
    // for (int a : days)
    //     cout << a << " ";
    // cout << endl;
    if (curr == 7)
    {
        if (days.size() < best_ans)
        {
            best_ans = days.size();
            allo = allocation;
            // debug1(days);
        }
        return;
    }
    for (int i = 0; i < dp[curr].size(); i++)
    {
        bool found = false;
        for (int j = 0; j < days.size() && !found; j++)
        {
            if (!((1 << dp[curr][i]) & days[j]))
            {
                vi new_days = days;
                new_days[j] = new_days[j] | (1 << dp[curr][i]);
                vvi new_allocation = allocation;
                new_allocation[j][dp[curr][i]] = curr;
                found = true;
                dfs(curr + 1, new_days, new_allocation);
            }
        }
        if (!found)
        {
            vi new_days = days;
            vvi new_allocation = allocation;
            new_allocation.pb(vi(7, -1));
            new_allocation.back()[dp[curr][i]] = curr;
            new_days.pb(1 << dp[curr][i]);
            dfs(curr + 1, new_days, new_allocation);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            int s;
            cin >> s;
            if (s == 1)
            {
                dp[j].pb(i);
                // cout << i << " " << j << endl;
            }
        }
    }

    // for (int i = 0; i < 7; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < dp[i].size(); j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vs names{"Twilight Sparkle", "Applejack", "Rarity", "Pinkie Pie", "Fluttershy", "Rainbow Dash", "Spike"};
    for (int i = 0; i < 7; i++)
    {
        if (dp[i].size() == 0)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    dfs(0, vi(), vvi());

    cout << allo.size() << endl;

    for (vi day : allo)
    {
        int ans = 0;
        vector<pair<string, int>> anss;
        for (int i = 0; i < 7; i++)
        {
            if (day[i] != -1)
            {
                ans++;
                anss.pb({names[i], day[i]});
            }
        }
        cout << ans << endl;
        for (auto [k, v] : anss)
        {
            cout << k << " " << v + 1 << endl;
        }
    }

    return 0;
}