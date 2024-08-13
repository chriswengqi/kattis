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
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vi ans;
    int curr = arr[0];
    ans.pb(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > curr)
        {
            curr = arr[i];
            ans.pb(arr[i]);
        }
    }

    cout << ans.size() << endl;
    for (int a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
}
