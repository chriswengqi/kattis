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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int k;
    cin >> k;
    int song = 1;
    vector<unordered_set<int>> songs(n + 1, unordered_set<int>());

    for (int i = 0; i < k; i++)
    {
        int s;
        cin >> s;
        vi arr(s);
        for (int j = 0; j < s; j++)
        {
            cin >> arr[j];
        }
        sort(arr.begin(), arr.end());
        unordered_set<int> curr;
        if (arr[0] == 1)
        {
            for (int a : arr)
            {
                if (a != 1)
                {
                    songs[a].insert(song);
                }
            }
            song++;
        }
        else
        {
            unordered_set<int> curr;
            for (int a : arr)
            {
                for (int b : songs[a])
                {
                    curr.insert(b);
                }
            }
            for (int a : arr)
            {
                if (a != 1)
                {
                    unordered_set<int> new_curr = curr;
                    songs[a] = new_curr;
                }
            }
        }
    }

    cout << 1 << endl;
    for (int i = 2; i <= n; i++)
    {
        if (songs[i].size() == song - 1)
        {
            cout << i << endl;
        }
    }

    return 0;
}
