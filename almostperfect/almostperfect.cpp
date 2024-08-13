#include <bits/stdc++.h>
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
    int n;

    while (cin >> n)
    {
        int pt = sqrt(n) + 1;

        int ans = 1;
        for (int i = 2; i < pt; i++)
        {
            if (n % i == 0)
            {
                ans += i;
                if (i != n / i)
                    ans += n / i;
            }
        }

        if (ans == n)
        {
            cout << n << " perfect" << endl;
        }
        else if (abs(ans - n) <= 2)
        {
            cout << n << " almost perfect" << endl;
        }
        else
        {
            cout << n << " not perfect" << endl;
        }
    }

    return 0;
}
