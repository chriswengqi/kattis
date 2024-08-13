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
    int n, m;
    cin >> n >> m;
    vpii arr(m);
    vi dic(m);
    for (int i = 0; i < m; i++)
    {
        int s;
        cin >> s;
        arr[i] = {s, i};
        dic[i] = s;
    }
    sort(arr.begin(), arr.end());
    int left = m;
    vi dic2(m);
    umap<int, priority_queue<int>> pq;
    for (int i = 0; i < m; i++)
    {
        int pay = min(arr[i].first, n / left);
        n -= pay;
        left--;
        dic2[arr[i].second] = pay;
        if (!pq.count(arr[i].first))
        {
            pq[arr[i].first] = priority_queue<int>();
        }
        pq[arr[i].first].push(pay);
    }
    if (n > 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (int i = 0; i < m; i++)
    {
        assert(pq[dic[i]].size() > 0);
        cout << pq[dic[i]].top() << " ";
        pq[dic[i]].pop();
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        solve();
    }

    return 0;
}