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
    string s, t;
    cin >> t >> s;
    int s1 = 0;
    int s0 = 0;
    int t1 = 0;
    int t0 = 0;
    int qs = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            s0++;
        }
        else
        {
            s1++;
        }

        if (t[i] == '0')
        {
            t0++;
        }
        else if (t[i] == '1')
        {
            t1++;
        }
        else
        {
            qs++;
        }
    }
    if (t1 + qs < s1 || t0 + qs < s0)
    {
        cout << -1 << endl;
        return;
    }
    int diff0 = s0 - t0;
    int diff1 = s1 - t1;
    int ans = 0;

    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '?')
        {
            if (s[i] == '0' && diff0 > 0)
            {
                t[i] = '0';
                diff0--;
            }
            else if (s[i] == '1' && diff1 > 0)
            {
                t[i] = '1';
                diff1--;
            }
            else if (diff1 > 0)
            {
                t[i] = '1';
                diff1--;
            }
            else
            {
                t[i] = '0';
                diff0--;
            }
            ans++;
        }
    }

    int total_diff = 0;

    for (int i = 0; i < t.size(); i++)
    {
        if (s[i] != t[i])
        {
            total_diff++;
        }
    }

    cout << ans + total_diff / 2 + total_diff % 2 << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
