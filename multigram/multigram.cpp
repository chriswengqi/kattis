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
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    vector<int> arr(26, 0);

    for (char c : s)
    {
        arr[c - 'a']++;
    }

    int gcd = 0;

    for (int a : arr)
    {
        gcd = __gcd(gcd, a);
    }
    // {2, 4}
    // gcd = 2

    if (gcd == 1)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < 26; i++)
    {
        arr[i] = arr[i] / gcd;
    }

    int size = s.size() / gcd;

    for (int i = 0; i < s.size(); i += size)
    {
        vi arr2(26, 0);
        for (int j = i; j < i + size; j++)
        {
            arr2[s[j] - 'a']++;
        }
        if (arr2 != arr)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << s.substr(0, size) << endl;

    return 0;
}
