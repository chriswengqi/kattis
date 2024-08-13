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
        vc arr(32, '?');
        for (int i = 0; i < n; i++)
        {
            string cmd;
            cin >> cmd;
            if (cmd == "SET")
            {
                int s;
                cin >> s;
                arr[s] = '1';
            }
            else if (cmd == "CLEAR")
            {
                int s;
                cin >> s;
                arr[s] = '0';
            }
            else if (cmd == "AND")
            {
                int s, t;
                cin >> s >> t;
                if (arr[s] == '1' && arr[t] == '1')
                {
                    continue;
                }
                else if (arr[s] == '0' || arr[t] == '0')
                {
                    arr[s] = '0';
                }
                else
                {
                    arr[s] = '?';
                }
            }
            else if (cmd == "OR")
            {
                int s, t;
                cin >> s >> t;
                if (arr[s] == '1' || arr[t] == '1')
                {
                    arr[s] = '1';
                }
                else if (arr[s] == '0' && arr[t] == '0')
                {
                    arr[s] = '0';
                }
                else
                {
                    arr[s] = '?';
                }
            }
        }

        for (int i = 31; i >= 0; i--)
        {
            cout << arr[i];
        }
        cout << endl;
        cin >> n;
    }

    return 0;
}
