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
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define INF 1e9
#define LLINF 4e18
#define sz(x) (int)x.size()
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

void solve()
{
    int n, m;
    cin >> n >> m;
    string _;
    getline(cin, _);
    vvi allvals;
    vvi allnegs;
    bool invalid = false;
    for (int i = 0; i < m; i++)
    {
        string s;
        getline(cin, s);
        vs clause;
        string curr = "";
        for (char c : s)
        {
            if (c == ' ' || c == '\n')
                continue;
            if (c == 'v')
            {
                clause.pb(curr);
                curr = "";
            }
            else
            {
                curr.pb(c);
            }
        }
        clause.pb(curr);
        vi bitmask(n, -1);

        vi vals;
        vi negs;

        for (string c : clause)
        {
            string tmp;
            for (char ch : c)
            {
                if (int(ch - '0') >= 0 && int(ch - '0') < 10)
                {
                    tmp.pb(ch);
                }
            }
            int val = stoi(tmp) - 1;
            int neg = (c[0] == '~' ? 1 : 0);
            vals.pb(val);
            negs.pb(neg);
        }
        allvals.pb(vals);
        allnegs.pb(negs);
    }

    for (int i = 0; i < (1 << n); i++)
    {
        bool can = true;
        for (int j = 0; j < allvals.size(); j++)
        {
            int clauses_can = false;
            for (int k = 0; k < allvals[j].size(); k++)
            {
                int yes = (((1 << allvals[j][k]) & i) ? 1 : 0);
                clauses_can |= (yes ^ (allnegs[j][k]));
            }
            can &= clauses_can;
            if (!can)
                break;
        }
        if (can)
        {
            cout << "satisfiable" << endl;
            return;
        }
    }

    cout << "unsatisfiable" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        solve();
    }

    return 0;
}