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

    int n, k;
    cin >> n >> k;
    int digits = 3;
    if (n < 10)
    {
        digits = 1;
    }
    else if (n < 100)
    {
        digits = 2;
    }

    int filled = n * k / 100;
    cout << "[";
    for (int i = 0; i < filled; i++)
    {
        cout << "#";
    }
    for (int i = 0; i < k - filled; i++)
    {
        cout << "-";
    }
    cout << "] |";
    for (int i = 0; i < 4 - digits; i++)
    {
        cout << " ";
    }
    cout << n << "%" << endl;

    return 0;
}
