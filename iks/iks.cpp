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

void solve()
{
    int n;
    cin >> n;
    umap<int, int> dic;
    vector<umap<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        arr[i] = addPrimeFactors(s);
        for (auto &[k, v] : arr[i])
        {
            if (!dic.count(k))
                dic[k] = 0;
            dic[k] += v;
        }
    }
    umap<int, int> ans;
    int ttl = 1;
    for (auto &[k, v] : dic)
    {
        if (v / n >= 1)
        {
            ans[k] = v / n;
            ttl *= pow(k, v / n);
        }
    }
    int moves = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto &[k, v] : ans)
        {
            if (!arr[i].count(k))
                moves += v;
            else
                moves += max(0LL, v - arr[i][k]);
        }
    }

    cout << ttl << " " << moves << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    TC = 1;

    while (TC--)
    {
        solve();
    }

    return 0;
}