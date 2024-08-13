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

void addPrimeFactors(int inp, unordered_map<int, int> &dic)
{
    int n = inp;
    while (n % 2 == 0)
    {
        if (!dic.count(2))
            dic[2] = 0;
        dic[2]++;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            if (!dic.count(i))
                dic[i] = 0;
            dic[i]++;
            n = n / i;
        }
    }
    if (n > 2)
    {
        if (!dic.count(n))
            dic[n] = 0;
        dic[n]++;
    }
}

int power(int x, int y, int m)
{
    if (y == 0)
        return 1;
    long p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    if (y % 2 == 0)
        return p;
    else
        return (x * p) % m;
}

int modInv(int a, int m)
{
    return power(a, m - 2, m);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    unordered_map<int, int> dic;
    unordered_map<int, int> dic2;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        addPrimeFactors(s, dic);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int s;
        cin >> s;
        addPrimeFactors(s, dic2);
    }
    int ans = 1;
    bool exc = false;
    for (auto [k, v] : dic2)
    {
        if (dic.count(k))
        {
            for (int i = 0; i < min(v, dic[k]); i++)
            {
                ans *= k;
                if (ans >= 1e9)
                {
                    exc = true;
                    ans %= 1000000000;
                }
            }
        }
    }

    if (!exc)
    {
        cout << ans << endl;
    }
    else
    {
        vc arr;
        while (ans != 0)
        {
            arr.pb('0' + (ans % 10));
            ans /= 10;
        }
        while (arr.size() < 9)
            arr.pb('0');
        for (int i = 8; i >= 0; i--)
            cout << arr[i];
        cout << endl;
    }

    return 0;
}
