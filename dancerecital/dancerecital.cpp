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
    vs arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 1e9;
    do
    {
        int curr_ans = 0;
        for (int i = 1; i < n; i++)
        {
            int ptr1 = 0;
            int ptr2 = 0;
            while (ptr1 < arr[i - 1].size() && ptr2 < arr[i].size())
            {
                if (arr[i - 1][ptr1] == arr[i][ptr2])
                {
                    curr_ans++;
                    ptr1++;
                    ptr2++;
                }
                else if (arr[i - 1][ptr1] < arr[i][ptr2])
                {
                    ptr1++;
                }
                else
                {
                    ptr2++;
                }
            }
        }
        ans = min(curr_ans, ans);
    } while (next_permutation(arr.begin(), arr.end()));

    cout << ans << endl;

    return 0;
}
