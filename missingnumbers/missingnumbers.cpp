#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
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

    int n;
    cin >> n;
    int curr = 1;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        while (s != curr)
        {
            cout << curr << endl;
            flag = true;
            curr++;
        }
        curr++;
    }

    if (!flag)
        cout << "good job" << endl;
    return 0;
}
