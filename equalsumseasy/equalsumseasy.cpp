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

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    umap<int, vi> dic;
    bool found = false;
    for (int i = 1; i <= (1LL << n) - 1 && !found; i++)
    {
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            if ((1LL << j) & i)
            {
                ans += arr[j];
            }
        }
        if (!dic.count(ans))
        {
            dic[ans] = {i};
        }
        else
        {
            dic[ans].pb(i);
        }
    }

    for (auto &[k, v] : dic)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                if ((v[i] & v[j]) == 0)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if ((1LL << k) & v[i])
                        {
                            cout << arr[k] << " ";
                        }
                    }
                    cout << endl;
                    for (int k = 0; k < n; k++)
                    {
                        if ((1LL << k) & v[j])
                        {
                            cout << arr[k] << " ";
                        }
                    }
                    cout << endl;
                    return;
                }
            }
        }
    }

    cout << "Impossible" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    for (int i = 1; i <= TC; i++)
    {
        cout << "Case #" << i << ":" << endl;
        solve();
    }

    return 0;
}