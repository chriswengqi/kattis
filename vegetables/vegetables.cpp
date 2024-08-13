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
#define backINT 1e18

struct compare
{
public:
    bool operator()(const pii &a, const pii &b) const
    {
        if (double((double)a.first / (double)a.second) == double((double)b.first / (double)b.second))
        {
            return true;
        }
        return double((double)a.first / (double)a.second) > double((double)b.first / (double)b.second);
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double m;
    int n;
    cin >> m >> n;
    vi arr(n);
    set<pii, compare> pq;
    for (int &a : arr)
    {
        cin >> a;
        pq.insert(mp(a, 1));
    }

    // auto front = *pq.begin();
    // auto back = *pq.rbegin();

    // cout << front.first << " " << back.first << endl;

    int ans = 0;

    while (true)
    {
        pii back = *pq.begin();
        pii front = *pq.rbegin();

        // cout << back.first << " " << back.second << endl;
        // cout << front.first << " " << front.second << endl;
        // cout << double(((double)front.first / (double)front.second) / ((double)back.first / (double)back.second)) << endl;

        if (double(((double)front.first / (double)front.second) / ((double)back.first / (double)back.second)) >= m)
        {
            break;
        }
        // cout << pq.size() << endl;
        pii curr = *pq.begin();
        pq.erase(pq.begin());
        curr.second++;
        pq.insert(mp(curr.first, curr.second));
        ans++;
    }

    cout << ans << endl;

    return 0;
}
