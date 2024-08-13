#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p;
    cin >> n >> m >> p;
    priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> q;

    for (int i = 0; i < n; i++)
    {
        string s;
        int t;
        cin >> s >> t;
        q.push({s, t});
    }
    q.push({"Jane Eyre", p});

    vector<tuple<int, string, int>> arr;
    for (int i = 0; i < m; i++)
    {
        int r;
        string s;
        int t;
        cin >> r >> s >> t;
        arr.pb({r, s, t});
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    int ptr = 0;

    while (true)
    {
        while (ptr < m && get<0>(arr[ptr]) < ans)
        {
            q.push({get<1>(arr[ptr]), get<2>(arr[ptr])});
            ptr++;
        }

        auto &[k, v] = q.top();
        ans += v;
        if (k == "Jane Eyre")
        {
            break;
        }
        q.pop();
    }

    cout << ans << endl;

    return 0;
}
