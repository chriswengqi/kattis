#include <bits/stdc++.h>

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
    while (n != 0)
    {
        vpii arr(n);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            arr[i] = {a, b};
        }

        int MOD = 20001;
        int mx = 1;

        for (int i = 0; i < n; i++)
        {
            umap<int, int> dic; // {x, y} : 20001 * x + y
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int x_diff = arr[j].first - arr[i].first;
                int y_diff = arr[j].second - arr[i].second;
                int slope;
                if (x_diff == 0) // treat as (0, 1)
                {
                    slope = 1;
                }
                else if (y_diff == 0) // treat as (1, 0)
                {
                    slope = MOD;
                }
                else
                {
                    int gcd = abs(__gcd(abs(x_diff), abs(y_diff)));
                    if (x_diff * y_diff > 0)
                    {
                        slope = abs(x_diff / gcd) * MOD + abs(y_diff / gcd);
                    }
                    else // (make x pos and y neg)
                    {
                        slope = abs(x_diff / gcd) * MOD - abs(y_diff / gcd);
                    }
                }
                if (!dic.count(slope))
                    dic[slope] = 0;
                dic[slope]++;
            }
            for (auto &[k, v] : dic)
            {
                // debug(k / MOD);
                // debug(k % MOD);
                // debug(v);
                mx = max(mx, v + 1);
            }
        }

        cout << mx << endl;

        cin >> n;
    }

    return 0;
}