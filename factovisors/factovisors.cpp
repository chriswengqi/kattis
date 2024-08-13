#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
typedef tuple<int, int, int> iii;

#define pb push_back
#define em emplace
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define INF 1e9
#define LLINF 4e18
#define umap unordered_map
#define uset unordered_set
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
#define debug1(a)                           \
    for (int i = 0; i <= a.size() - 1; i++) \
    cout << a[i] << (i == a.size() - 1 ? '\n' : ' ')
#define debug2(a)                                  \
    for (int i = 0; i <= a.size() - 1; i++)        \
        for (int j = 0; j <= a[0].size() - 1; j++) \
    cout << a[i][j] << (j == a[0].size() - 1 ? '\n' : ' ')

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

umap<int, int> addPrimeFactors(int inp)
{
    unordered_map<int, int> dic;
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

    return dic;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while (cin >> n >> m)
    {
        if (m == 0)
        {
            cout << m << " does not divide " << n << "!" << endl;
            continue;
        }
        umap<int, int> dic = addPrimeFactors(m);

        bool valid = true;
        for (auto &[k, v] : dic)
        {
            int ttl = 0;
            int tmp = n;
            while (tmp > 1)
            {
                ttl += tmp / k;
                tmp /= k;
            }

            if (ttl < v)
            {
                valid = false;
                break;
            }
        }

        cout << m << (valid ? " divides " : " does not divide ") << n << "!" << endl;
    }
    return 0;
}