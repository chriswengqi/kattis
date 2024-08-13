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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n != 0)
    {
        string s;
        int k;
        int curr1 = 0;
        int curr2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> k;
            if (s == "DROP")
            {
                curr2 += k;
                cout << "DROP 2 " << k << endl;
            }
            else
            {
                if (curr1 >= k)
                {
                    cout << "TAKE 1 " << k << endl;
                    curr1 -= k;
                }
                else
                {
                    cout << "MOVE 2->1 " << curr2 << endl;
                    curr1 += curr2;
                    curr2 = 0;
                    cout << "TAKE 1 " << k << endl;
                    curr1 -= k;
                }
            }
        }

        cout << endl;

        cin >> n;
    }

    return 0;
}
