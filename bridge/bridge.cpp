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
    vi arr(n);
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int a : arr)
        dq.push_back(a);

    int time = 0;
    vvi ans;
    while (dq.size() > 0)
    {
        if (dq.size() == 3)
        {
            int f = dq.front();
            int s1 = dq.back();
            dq.pop_back();
            int s2 = dq.back();
            time += f + s1 + s2;
            ans.pb({f, s1});
            ans.pb({f});
            ans.pb({f, s2});
            break;
        }
        else if (dq.size() == 2)
        {
            int f = dq.front();
            int s = dq.back();
            time += s;
            ans.pb({f, s});
            break;
        }
        else if (dq.size() == 1)
        {
            int f = dq.front();
            time += f;
            ans.pb({f});
            break;
        }
        else
        {
            int f1 = dq.front();
            dq.pop_front();
            int f2 = dq.front();
            dq.pop_front();
            int s1 = dq.back();
            dq.pop_back();
            int s2 = dq.back();
            dq.pop_back();

            // strat 1: {f1, s1}, {f1}, {f1, s2}, {f1}
            int strat1 = s1 + s2 + 2 * f1;
            // strat 2: {f1, f2}, {f1}, {s1, s2}, {f2}
            int strat2 = 2 * f2 + f1 + s1;

            if (strat1 < strat2)
            {
                time += strat1;
                ans.pb({f1, s1});
                ans.pb({f1});
                ans.pb({f1, s2});
                ans.pb({f1});
            }
            else
            {
                time += strat2;
                ans.pb({f1, f2});
                ans.pb({f1});
                ans.pb({s2, s1});
                ans.pb({f2});
            }

            dq.push_front(f2);
            dq.push_front(f1);

            // debug(dq.size());
        }
    }

    cout << time << endl;
    for (vi &vec : ans)
    {
        for (int a : vec)
        {
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}