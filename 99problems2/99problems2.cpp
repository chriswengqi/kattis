#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    scanf("%d %d ", &n, &q);
    multiset<int> dic;

    for (int i = 0; i < n; i++)
    {
        int d;
        scanf("%d ", &d);
        dic.insert(d);
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if (a == 1)
        {
            auto it = dic.upper_bound(b);
            if (it != dic.end())
            {
                printf("%d\n", *it);
                dic.erase(it);
            }
            else
            {
                printf("-1\n");
            }
        }
        else
        {
            auto it = dic.lower_bound(b);
            if (*it != b)
            {
                if (it == dic.begin())
                {
                    printf("-1\n");
                }
                else
                {
                    it--;
                    printf("%d\n", *it);
                    dic.erase(it);
                }
            }
            else
            {
                printf("%d\n", *it);
                dic.erase(it);
            }
        }
    }

    return 0;
}
