#include <bits/stdc++.h>
#include <algorithm>
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

void solve()
{
    int N;
    cin >> N;
    ll total = 0;
    for (int i = 0; i < N; i++)
    {
        ll k;
        cin >> k;
        total += k % N;
    }

    if (total % N == 0)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;

    cin >> TC;
    for (int i = 0; i < TC; i++)
    {
        solve();
    }
}
