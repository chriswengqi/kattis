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

    int n;
    cin >> n;
    vector<int> arr(1000001, 0);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (arr[k + 1] == 0)
        {
            arr[k]++;
            ans++;
        }
        else
        {
            arr[k + 1]--;
            arr[k]++;
        }
    }

    cout << ans << endl;
    return 0;
}
