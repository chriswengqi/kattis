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

void solve()
{
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int, int> dic;
    int curr = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        curr *= i;
        while (curr % 10 == 0)
        {
            curr = curr / 10;
        }
        dic[i] = curr % 10;

        curr = curr % 1000000000;
    }

    int n;
    cin >> n;
    while (n != 0)
    {
        cout << dic[n] << endl;

        cin >> n;
    }

    return 0;
}
