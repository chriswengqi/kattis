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

int main()
{
    ll n;
    cin >> n;
    ll d = 128;
    while (true)
    {
        ll curr = 1;
        for (int i = 0; i < 9; i++)
        {
            curr = curr * d;
        }
        if (n % curr == 0)
        {
            cout << d << endl;
            return 0;
        }
        d--;
    }
}
