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
    string s1, s2;
    cin >> s1 >> s2;
    bool ans;
    if (n % 2 == 0)
    {
        if (s1 == s2)
            ans = true;
        else
            ans = false;
    }
    else
    {
        bool flag = true;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == s2[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            ans = true;
        else
            ans = false;
    }

    cout << "Deletion " << (ans ? "succeeded" : "failed") << endl;
    return 0;
}
