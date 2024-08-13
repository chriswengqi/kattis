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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << endl;

    return 0;
}
