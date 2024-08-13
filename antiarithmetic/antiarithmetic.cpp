#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
typedef tuple<int, int, int> iii;

#define pb push_back
#define em emplace
#define mp make_pair
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define INF 1e9
#define LLINF 4e18
#define umap unordered_map
#define uset unordered_set
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
#define debug1(a)                           \
    for (int i = 0; i <= a.size() - 1; i++) \
    cout << a[i] << (i == a.size() - 1 ? '\n' : ' ')
#define debug2(a)                                  \
    for (int i = 0; i <= a.size() - 1; i++)        \
        for (int j = 0; j <= a[0].size() - 1; j++) \
    cout << a[i][j] << (j == a[0].size() - 1 ? '\n' : ' ')

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    scanf("%s", &s);
    while (s != "0")
    {
        int n = 0;
        for (char c : s)
        {
            if (c == ':')
                break;
            n *= 10;
            n += int(c - '0');
        }
        vi arr(n);
        vi pos(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            pos[arr[i]] = i;
        }
        bool valid = true;

        for (int i = 0; i < n && valid; i++)
        {
            for (int j = -n + 1; j < n && valid; j++)
            {
                if (i + 2 * j >= 0 && i + 2 * j < n && pos[i] < pos[i + j] && pos[i + j] < pos[i + 2 * j])
                {
                    valid = false;
                    break;
                }
            }
        }

        cout << (valid ? "yes" : "no") << '\n';

        scanf("%s", &s);
    }

    return 0;
}