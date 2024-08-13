#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    vi arr{1, 0, 0};

    for (char c : s)
    {
        if (c == 'A')
            swap(arr[0], arr[1]);
        else if (c == 'B')
            swap(arr[1], arr[2]);
        else
            swap(arr[0], arr[2]);
    }
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] == 1)
        {
            cout << i + 1 << endl;
        }
    }
    return 0;
}
