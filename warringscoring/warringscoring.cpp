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
    vs arr(n);

    int py = 0;
    int pn = 0;
    int y_leads = 0;
    int n_leads = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == "Yraglac")
        {
            py++;
        }
        else
        {
            pn++;
        }
        y_leads = max(y_leads, py - pn);
        n_leads = max(n_leads, pn - py);
    }
    int max_y, max_z = 0;
    int y_cons, z_cons = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == "Yraglac")
        {
            y_cons++;
            z_cons = 0;
        }
        else
        {
            z_cons++;
            y_cons = 0;
        }
        max_y = max(max_y, y_cons);
        max_z = max(max_z, z_cons);
    }

    if ((max_y > max_z && y_leads > n_leads) || (max_y < max_z && y_leads < n_leads) || (max_y == max_z && y_leads == n_leads))
    {
        cout << "Agree" << endl;
    }
    else
    {
        cout << "Disagree" << endl;
    }
    return 0;
}
