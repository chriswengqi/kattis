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
    ll total = 0;
    for (int &a : arr)
    {
        cin >> a;
        total += a;
    }

    ll tf = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        tf += arr[i] * arr[i];
        total -= arr[i];
        ans = max(ans, total * tf);
    }

    cout << ans << endl;

    return 0;
}
