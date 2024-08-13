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

    int n, k;
    cin >> n >> k;
    int total = 0;
    vi arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    int left = *max_element(arr.begin(), arr.end());
    int right = total;

    while (left < right)
    {
        int mid = (left + right) / 2;
        int boxes = 1;
        int curr_box = 0;
        for (int i = 0; i < n; i++)
        {
            if (curr_box + arr[i] > mid)
            {
                boxes++;
                curr_box = arr[i];
            }
            else
            {
                curr_box += arr[i];
            }
        }
        if (boxes > k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    cout << left << endl;

    return 0;
}
