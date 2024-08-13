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

int count(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int curr = 0;
        int power = 1;
        for (int j = k - 1; j >= 0; j--)
        {
            if (s[j] == 'T')
            {
                curr += power;
            }
            power *= 2;
        }
        arr[i] = curr;
    }

    int maxx = (1 << k) - 1;
    int best_ans = 0;
    for (int i = 0; i <= maxx; i++)
    {
        int worst_ans = k;
        for (int a : arr)
        {
            int bitwise = a ^ i;
            worst_ans = min(worst_ans, k - count(bitwise));
        }
        best_ans = max(best_ans, worst_ans);
    }

    cout << best_ans << endl;

    return 0;
}
