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

    int q;
    cin >> q;
    int ans = 1;

    if (q == 1)
    {
        cout << "no" << endl;
        return 0;
    }

    if (is_prime(q))
    {
        cout << "yes" << endl;
        return 0;
    }

        for (int i = 2; i <= sqrt(q); i++)
    {
        if (q % i == 0 && is_prime(i))
        {
            ans = i;
            break;
        }
    }

    while (q > 1)
    {
        if (q % ans != 0)
        {
            cout << "no" << endl;
            return 0;
        }

        q = q / ans;
    }

    cout << "yes" << endl;

    return 0;
}
