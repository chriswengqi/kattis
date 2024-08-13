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
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int s, d;
        cin >> s >> d;
        int x = (s + d) / 2;
        int y = (s - d) / 2;

        if (y < 0 || (x + y) != s)
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << x << " " << y << endl;
        }
    }
}
