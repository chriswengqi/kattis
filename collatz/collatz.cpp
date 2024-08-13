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

void solve(int a, int b, int c, int d, int e)
{
    cout << a << " needs " << b << " steps, " << c << " needs " << d << " steps, they meet at " << e << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    while (x != 0 && y != 0)
    {

        int n = x;
        int m = y;
        int count = 0;
        bool flag = true;
        unordered_map<int, int> dic;
        dic[1] = 0;
        while (flag)
        {
            dic[n] = count;
            if (n == m)
            {
                flag = false;
                solve(x, count, y, 0, m);
                break;
            }
            if (n == 1)
                break;
            if (n % 2 == 0)
            {
                n = n / 2;
            }
            else
            {
                n = 3 * n + 1;
            }
            count++;
        }

        if (flag)
        {
            int count2 = 0;
            while (true)
            {
                if (dic.count(m))
                {
                    solve(x, dic[m], y, count2, m);
                    break;
                }

                if (m == 1)
                {
                    break;
                }

                if (m % 2 == 0)
                {
                    m = m / 2;
                }
                else
                {
                    m = 3 * m + 1;
                }
                count2++;
            }
        }

        cin >> x >> y;
    }

    return 0;
}
