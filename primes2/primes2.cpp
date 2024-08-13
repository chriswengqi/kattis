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

int binary(string s, int base)
{
    string dic = "0123456789ABCDEF";
    unordered_map<char, int> conv;
    for (int i = 0; i < 16; i++)
    {
        conv[dic[i]] = i;
    }

    int ans = 0;
    int b = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        ans += b * conv[s[i]];
        b *= base;
    }

    // cout << ans << " " << base << endl;

    return ans;
}

bool is_prime(int x)
{
    if (x < 2)
        return false;
    if (x == 2)
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

void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    int bases = 4;
    vi bases_arr = {16, 10, 8, 2};
    for (char c : s)
    {
        if (c > '9')
        {
            bases = min(1LL, bases);
        }
        else if (c > '7')
        {
            bases = min(2LL, bases);
        }
        else if (c > '1')
        {
            bases = min(3LL, bases);
        }
    }

    for (int i = 0; i < bases; i++)
    {
        if (is_prime(binary(s, bases_arr[i])))
        {
            ans++;
        }
    }

    int gcd = __gcd(ans, bases);

    cout << ans / gcd << "/" << bases / gcd << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        solve();
    }

    return 0;
}
