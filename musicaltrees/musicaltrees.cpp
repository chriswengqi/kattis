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

void solve()
{
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vi people(n);
    map<int, int> trees;

    for (int i = 0; i < n; i++)
    {
        cin >> people[i];
    }

    for (int i = 0; i < m; i++)
    {
        int s;
        cin >> s;
        trees[s] = 0;
    }

    int trees_min = trees.begin()->first;
    int trees_max = trees.rbegin()->first;

    for (int a : people)
    {
        if (a < trees_min)
        {
            trees[trees_min]++;
        }
        else if (a > trees_max)
        {
            trees[trees_max]++;
        }
        else
        {
            auto it = trees.lower_bound(a);
            pii left = *it--;
            pii right = *it;

            // cout << a << " " << left.first << " " << right.first << endl;

            if (abs(a - left.first) < abs(a - right.first))
            {
                trees[left.first]++;
            }
            else
            {
                trees[right.first]++;
            }
        }
    }

    int ans = 0;
    for (auto &[k, v] : trees)
    {
        // cout << k << " " << v << endl;
        if (v > 1)
            ans += (v - 1);
    }

    cout << ans << endl;

    return 0;
}
