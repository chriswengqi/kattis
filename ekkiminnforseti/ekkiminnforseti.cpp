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

class compare
{
public:
    bool operator()(pii below, pii above)
    {
        if (below.first > above.first)
        {
            return true;
        }
        else if (below.first == above.first && below.second < above.second)
        {
            return true;
        }

        return false;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vs people(k);
    for (int i = 0; i < k; i++)
    {
        cin >> people[i];
    }

    vvi grid();
    for (int i = 0; i < n; i++)
    {
        vi curr;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            curr.pb(x);
        }
        reverse(curr.begin(), curr.end());
        grid.pb(curr);
    }
    vector<unordered_set<int>> best(k, unordered_set<int>());
    priority_queue<pii, vector<pii>, compare> pq;
    vi counts(k, 0);
    for (int i = 0; i < n; i++)
    {
        counts[grid[i].back() - 1]++;
        best[grid[i].back() - 1].insert(i);
    }

    for (int i = 0; i < k; i++)
    {
        pq.push({counts[i], i});
    }

    while (*max_element(counts.begin(), counts.end()) < n / 2 + 1)
    {
        pii curr = pq.top();
        while (curr.first != counts[curr.second])
        {
            pq.pop();
            if (counts[curr.second] != -1)
            {
                pq.push({counts[curr.second], curr.second});
            }
            curr = pq.top();
        }
        pq.pop();
        counts[curr.second] = -1;
        for (int a : best[curr.second])
        {
            while (counts[grid[a].back()] == -1)
                grid[a].pop_back();
            counts[grid[a].back() - 1]++;
            best[grid[a].back() - 1].insert(a);
        }
    }

    int maxx = 0;
    int curr_max = 0;
    for (int i = 0; i < k; i++)
    {
        if (counts[i] > maxx)
        {
            maxx = counts[i];
            curr_max = i;
        }
    }

    cout << people[curr_max] << endl;

    return 0;
}
