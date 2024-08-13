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
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c)
    {
        cout << a << endl;
        return 0;
    }

    int x = abs(a - b);
    int y = abs(a - c);
    int g = __gcd(x, y);

    int start = min(a, min(b, c));
    while (start == a || start == b || start == c)
    {
        start += g;
    }

    cout << start << endl;
}
