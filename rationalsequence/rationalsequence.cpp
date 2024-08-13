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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int S;
        int x;
        char _;
        int y;
        cin >> S >> x >> _ >> y;

        if (x < y)
        {
            cout << S << " " << y << "/" << y - x << endl;
        }
        else if (y == 1)
        {
            cout << S << " " << 1 << "/" << x + 1 << endl;
        }
        else
        {
            int curr = abs(x - y);
            cout << S << " " << y << "/" << abs((curr - y)) + y
        }
    }
}
