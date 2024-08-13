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
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
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
    unordered_map<int, int> dic;
    bool ans = true;

    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        dic[s] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        if ((dic[s] - i) % 2 == 1)
            ans = false;
    }

    cout << (ans ? "Possible" : "Impossible") << endl;

    return 0;
}
