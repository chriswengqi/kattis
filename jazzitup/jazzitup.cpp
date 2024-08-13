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

bool is_prime(int x)
{
    if (x == 2)
        return true;
    else
    {
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 2; i < n; i++)
    {
        if (is_prime(i) && n % i != 0)
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
