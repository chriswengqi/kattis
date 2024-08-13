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
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n != 0)
    {
        vpii arr;
        vi dp(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int s;
            double t;
            cin >> s >> t;
            int tt = t * 100 + 1e-6;
            // cout << tt << endl;
            arr.pb({s, tt});
            dp[i + 1] = arr[i].second + dp[i];
        }
        int max_profit = 0;
        int start = 0;
        int end = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int curr = dp[j + 1] - dp[i] - (arr[j].first - arr[i].first + 1) * 8;
                if (curr > max_profit)
                {
                    max_profit = curr;
                    start = arr[i].first;
                    end = arr[j].first;
                }
                else if (curr == max_profit && (arr[j].first - arr[i].first < end - start))
                {
                    start = arr[i].first;
                    end = arr[j].first;
                }
                else if (curr == max_profit && (arr[j].first - arr[i].first == end - start))
                {
                    if (arr[i].first < start)
                    {
                        start = arr[i].first;
                        end = arr[j].first;
                    }
                }
            }
        }
        if (max_profit > 0)
        {
            cout << max_profit / 100 << "." << max_profit % 100 << " " << start << " " << end << endl;
        }
        else
        {
            cout << "no profit" << endl;
        }

        cin >> n;
    }

    return 0;
}
