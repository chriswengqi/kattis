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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    vector<int> arr{0};
    int blue = 0;
    int red = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R')
            red++;
        else
            blue++;
        arr.pb(red - blue);
    }

    int peak = arr[0];
    int peak_index = 0;
    int valley = arr[0];
    int valley_index = 0;
    int ans = 1;

    for (int i = 1; i <= s.size(); i++)
    {
        if (arr[i] > peak)
        {
            peak = arr[i];
            peak_index = i;
        }
        if (arr[i] < valley)
        {
            valley = arr[i];
            valley_index = i;
        }

        if (arr[peak_index] - arr[valley_index] > ans)
        {
            ans = arr[peak_index] - arr[valley_index];
        }
    }

    if (peak_index < valley_index)
    {
        cout << peak_index + 1 << " " << valley_index << endl;
    }
    else
    {
        cout << valley_index + 1 << " " << peak_index << endl;
    }

    return 0;
}
