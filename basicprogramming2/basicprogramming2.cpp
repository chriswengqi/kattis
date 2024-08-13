#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    switch (k)
    {
    case 1:
    {
        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            if (arr[l] + arr[r] < 7777)
            {
                l++;
            }
            else if (arr[l] + arr[r] > 7777)
            {
                r--;
            }
            else
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }
    case 2:
    {
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
            {
                cout << "Contains duplicate" << endl;
                return 0;
            }
        }
        cout << "Unique" << endl;
        return 0;
    }
    case 3:
    {
        umap<int, int> dic;
        for (int a : arr)
        {
            if (!dic.count(a))
            {
                dic[a] = 0;
            }
            dic[a]++;
            if (dic[a] > n / 2)
            {
                cout << a << endl;
                return 0;
            }
        }
        cout << -1 << endl;
        return 0;
    }
    case 4:
    {
        if (n & 1)
        {
            cout << arr[n / 2] << endl;
        }
        else
        {
            cout << arr[n / 2 - 1] << " " << arr[n / 2] << endl;
        }
        break;
    }
    case 5:
    {
        for (int a : arr)
        {
            if (a >= 100 && a <= 999)
                cout << a << " ";
        }
        cout << endl;
        break;
    }
    default:
        break;
    }

    return 0;
}