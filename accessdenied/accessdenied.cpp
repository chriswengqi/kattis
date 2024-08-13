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

    int TC;
    cin >> TC;
    while (TC--)
    {
        int n, m;
        cin >> n >> m;
        vi p(n);

        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        int curr_total = 0;
        int left = 0;
        int prev_m = -1;
        int max_total = 0;

        for (int i = 0; i < n; i++)
        {
            if (p[i] != m)
            {
                curr_total += p[i];
                max_total = max(max_total, curr_total);
            }
            else
            {
                if (prev_m == -1)
                {
                    prev_m = i;
                    curr_total += p[i];
                    max_total = max(max_total, curr_total);
                    continue;
                }
                else
                {
                    while (left <= prev_m)
                    {
                        curr_total -= p[left];
                        left++;
                    }
                    prev_m = i;
                    curr_total += p[i];
                    max_total = max(max_total, curr_total);
                }
            }
        }
        cout << max_total << endl;
    }

    return 0;
}
