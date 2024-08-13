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

vi computeLPSArray(string pat)
{
    int len = 0;
    vi lps(pat.size());
    lps[0] = 0;

    int i = 1;
    while (i < lps.size())
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {

            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vi KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    vi lps = computeLPSArray(pat);
    vi ans;

    int i = 0;
    int j = 0;
    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            ans.pb(i - j);
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string pat, txt;

    while (getline(cin, pat) && getline(cin, txt))
    {
        vi ans = KMPSearch(pat, txt);
        if (ans.size() > 0)
        {
            for (int a : ans)
            {
                cout << a << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
