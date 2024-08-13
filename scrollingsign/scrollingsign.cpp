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

void solve()
{
    int n, k;
    cin >> k;
    vs arr(k);
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }

    string prev = arr[0];
    for (int i = 1; i < k; i++)
    {
        int curr = 0;
        while (prev[curr] != arr[i][0])
        {
            curr++;
            if (curr < n && prev[curr] == arr[i][0])
            {
                int next = curr;
                while (next < n && prev[next] == arr[i][next - curr])
                {
                    next++;
                }
                if (next != n)
                {
                    continue;
                }
                else
                {
                    prev += arr[i].substr(curr, n - curr);
                }
            }
            else
            {
                prev += arr[i];
                break;
            }
        }

        cout << prev << endl;
    }
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
