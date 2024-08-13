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

void solve()
{
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vi arr(n + 1, 0);
    int ctr = 0;

    int start = 2;
    int flag = true;
    while (start <= n && flag)
    {
        int multiple = 1;
        while (start * multiple <= n)
        {
            if (arr[start * multiple] == 0)
            {
                arr[start * multiple] = 1;

                ctr++;
                if (ctr == k)
                {
                    cout << start * multiple << endl;
                    flag = false;
                    break;
                }
            }

            multiple++;
        }

        while (arr[start] == 1 && flag)
            start++;
    }

    return 0;
}
