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
    int C, n;
    cin >> C >> n;
    bool flag = true;
    int curr = C;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        curr = curr - a + b;
        if (i == 0 && a > 0)
        {
            flag = false;
        }
        if (i == n - 1 && (b > 0 || c > 0))
        {
            flag = false;
        }
        if (curr < 0 || curr > C)
        {
            flag = false;
        }
        if (curr >= c)
        {
            flag = false;
        }
    }

    if (flag)
        cout << "possible" << endl;
    else
        cout << "impossible" << endl;
}
