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
typedef pair<long double, long double> pdd;
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
    int n, k;
    cin >> n >> k;
    vi arr;
    umap<int, pdd> dic;
    for (int i = 0; i < n; i++)
    {
        int x;
        long double y, z;
        cin >> x >> y >> z;
        arr.pb(z);
        dic[z] = {x, y};
    }
    vector<tuple<int, long double, long double>> arr2;
    for (int i = 0; i <= arr.back(); i += k)
    {
        auto it = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
        if (arr[it] == i)
        {
            arr2.pb({i, dic[arr[it]].first, dic[arr[it]].second});
        }
        else
        {
            assert(it > 0 && it < n);
            long double prev_x = dic[arr[it - 1]].first;
            long double prev_y = dic[arr[it - 1]].second;
            long double curr_x = dic[arr[it]].first;
            long double curr_y = dic[arr[it]].second;
            long double tmp_x = prev_x + ((long double)i - (long double)arr[it - 1]) / ((long double)arr[it] - (long double)arr[it - 1]) * (curr_x - prev_x);
            long double tmp_y = prev_y + ((long double)i - (long double)arr[it - 1]) / ((long double)arr[it] - (long double)arr[it - 1]) * (curr_y - prev_y);
            arr2.pb({i, tmp_x, tmp_y});
        }
    }

    if (arr.back() % k)
    {
        arr2.pb({arr.back(), dic[arr.back()].first, dic[arr.back()].second});
    }
    long double ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += sqrt((dic[arr[i]].first - dic[arr[i - 1]].first) * (dic[arr[i]].first - dic[arr[i - 1]].first) + (dic[arr[i]].second - dic[arr[i - 1]].second) * (dic[arr[i]].second - dic[arr[i - 1]].second));
    }
    long double pred = 0;

    for (int i = 1; i < arr2.size(); i++)
    {
        pred += sqrt((get<1>(arr2[i]) - get<1>(arr2[i - 1])) * (get<1>(arr2[i]) - get<1>(arr2[i - 1])) + (get<2>(arr2[i]) - get<2>(arr2[i - 1])) * (get<2>(arr2[i]) - get<2>(arr2[i - 1])));
    }

    assert(ans >= pred);

    cout << fixed << setprecision(10) << (ans - pred) / ans * 100 << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    TC = 1;

    while (TC--)
    {
        solve();
    }

    return 0;
}