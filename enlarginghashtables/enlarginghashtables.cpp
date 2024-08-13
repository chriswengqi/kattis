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

bool is_prime(int x)
{
    if (x <= 2)
        return true;
    else
    {
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
                return false;
        }
    }
    return true;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n != 0)
    {
        int np = 2 * n + 1;
        while (!is_prime(np))
            np += 2;
        cout << np << " ";
        if (!is_prime(n))
        {
            cout << "(" << n << " is not prime)";
        }
        cout << endl;
        cin >> n;
    }

    return 0;
}
