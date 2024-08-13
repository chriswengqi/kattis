#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    multiset<int> pq;
    vector<pii> times;
    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        int s, f;
        cin >> s >> f;
        times.pb(mp(f, s));
    }

    sort(times.begin(), times.end());

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            pq.insert(-times[i].first - 1);
        else
        {
            multiset<int>::iterator it = pq.lower_bound(-times[i].second);
            if (it != pq.end())
            {
                pq.erase(it);
                pq.insert(-times[i].first - 1);
                ans++;
            }
            else if (pq.size() < k)
            {
                pq.insert(-times[i].first - 1);
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}