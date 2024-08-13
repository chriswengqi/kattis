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

ll gcd(ll a, ll b)
{
    ll maxx = max(a, b);
    ll minn = min(a, b);

    if (maxx % minn == 0)
    {
        return minn;
    }
    else
    {
        return gcd(maxx % minn, minn);
    }
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    return a * b / g;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll curr = arr[0];
    for (int i = 1; i < n; i++)
    {
        curr = lcm(curr, arr[i]);
        if (curr > 1e9)
        {
            cout << "More than a billion." << endl;
            return;
        }
    }

    cout << curr << endl;
}

int main()
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
