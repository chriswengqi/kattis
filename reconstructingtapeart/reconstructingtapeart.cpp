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
    vi arr(n);
    unordered_map<int, vector<int>> dic;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (!dic.count(arr[i]))
        {
            dic[arr[i]] = {i + 1, i + 1};
        }
        else
        {
            dic[arr[i]] = {dic[arr[i]][0], i + 1};
        }
    }

    return 0;
}
