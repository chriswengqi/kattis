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
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

struct compare
{
public:
    bool operator()(pii a, pii b)
    {
        return double((double)a.first / (double)a.second) < double((double)b.first / (double)b.second);
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    while (n != -1 && m != -1)
    {
        vi arr(n);
        priority_queue<pii, vpii, compare> pq;
        for (int &a : arr)
        {
            cin >> a;
            pq.push({a, 1});
        }

        for (int i = n + 1; i <= m; i++)
        {
            auto [a, b] = pq.top();
            pq.pop();
            pq.push({a, b + 1});
        }

        int ans = (pq.top().first / pq.top().second) + (pq.top().first % pq.top().second != 0 ? 1 : 0);

        cout << ans << endl;

        cin >> n >> m;
    }

    return 0;
}
