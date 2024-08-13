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
#define sz(x) (int)x.size()
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
    vpii neg;
    vpii pos;
    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        if (s < 0)
        {
            neg.pb({s, t});
        }
        else if (s > 0)
        {
            pos.pb({s, t});
        }
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end(), greater<pii>());
    int ans = 0;
    for (int i = 0; i < neg.size(); i++)
    {
        if (neg[i].second == 0)
            continue;
        int dst = abs(neg[i].first);
        int trips = (neg[i].second + k - 1) / k;
        int rem = (neg[i].second % k == 0 ? 0 : k - neg[i].second % k);
        int curr = i + 1;
        while (rem > 0 && curr < neg.size())
        {
            int deduct = min(rem, neg[curr].second);
            neg[curr].second -= deduct;
            rem -= deduct;
            curr++;
        }
        ans += trips * 2 * dst;
    }

    for (int i = 0; i < pos.size(); i++)
    {
        if (pos[i].second == 0)
            continue;
        int dst = abs(pos[i].first);
        int trips = (pos[i].second + k - 1) / k;
        int rem = (pos[i].second % k == 0 ? 0 : k - pos[i].second % k);
        int curr = i + 1;

        while (rem > 0 && curr < pos.size())
        {
            int deduct = min(rem, pos[curr].second);
            pos[curr].second -= deduct;
            rem -= deduct;
            curr++;
        }
        ans += trips * 2 * dst;
    }

    cout << ans << endl;
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