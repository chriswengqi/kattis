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

void solve()
{
    int n, k;
    cin >> n >> k;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (k == 1)
        cout << 7 << endl;
    else if (k == 2)
        if (arr[0] > arr[1])
            cout << "Bigger" << endl;
        else if (arr[0] < arr[1])
            cout << "Smaller" << endl;
        else
            cout << "Equal" << endl;
    else if (k == 3)
    {
        vi tmp{arr[0], arr[1], arr[2]};
        sort(tmp.begin(), tmp.end());
        cout << tmp[1] << endl;
    }
    else if (k == 4)
    {
        int ttl = 0;
        for (int a : arr)
            ttl += a;
        cout << ttl << endl;
    }

    else if (k == 5)
    {
        int ttl = 0;
        for (int a : arr)
            if (a % 2 == 0)
                ttl += a;
        cout << ttl << endl;
    }
    else if (k == 6)
    {
        vi tmp(n);
        for (int i = 0; i < n; i++)
            tmp[i] = arr[i] % 26;
        for (int i = 0; i < n; i++)
            cout << char(tmp[i] + 'a');
        cout << endl;
    }
    else
    {
        vi visited(n, 0);
        int curr = 0;
        while (true)
        {
            visited[curr] = 1;
            curr = arr[curr];
            if (curr == n - 1)
            {
                cout << "Done" << endl;
                return;
            }

            if (curr >= n)
            {
                cout << "Out" << endl;
                return;
            }
            if (visited[curr])
            {
                cout << "Cyclic" << endl;
                return;
            }
        }
    }
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