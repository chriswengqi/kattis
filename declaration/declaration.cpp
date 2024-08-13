#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
    int n;
    cin >> n;
}

vs words1;
vs words2;
vvi dp;
vector<vpii> p;

int dfs(int i, int j)
{
    // cout << i << " " << j << " " << curr << endl;
    if (i == words1.size() && j == words2.size())
    {
        return 0;
    }
    else if (i == words1.size())
        return words2.size() - j;
    else if (j == words2.size())
        return words1.size() - i;
    else
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (words1[i] == words2[j])
        {
            p[i][j] = {i + 1, j + 1};
            return dp[i][j] = 1 + dfs(i + 1, j + 1);
        }
        else
        {
            int down = dfs(i + 1, j);
            int right = dfs(i, j + 1);
            if (down < right)
            {
                p[i][j] = {i + 1, j};
            }
            else if (down > right)
            {
                p[i][j] = {i, j + 1};
            }
            else
            {
                if (words1[i] < words2[j])
                    p[i][j] = {i + 1, j};
                else
                    p[i][j] = {i, j + 1};
            }
            return dp[i][j] = 1 + min(down, right);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    getline(cin, s);

    while (true)
    {
        getline(cin, t);
        size_t pos = 0;
        std::string token;
        words1.clear();
        words2.clear();
        while ((pos = s.find(" ")) != std::string::npos)
        {
            token = s.substr(0, pos);
            words1.pb(token);
            s.erase(0, pos + 1);
        }
        pos = 0;
        while ((pos = t.find(" ")) != std::string::npos)
        {
            token = t.substr(0, pos);
            words2.pb(token);
            t.erase(0, pos + 1);
        }
        dp.assign(words1.size() + 5, vi(words2.size() + 5, -1));
        p.assign(words1.size() + 5, vpii(words2.size() + 5, {-1, -1}));
        dfs(0, 0);

        int i = 0;
        int j = 0;
        while (i < words1.size() && j < words2.size())
        {
            auto [x, y] = p[i][j];
            if (x == i + 1 && y == j + 1)
            {
                cout << words1[i] << " ";
            }
            else if (x == i + 1)
            {
                cout << words1[i] << " ";
            }
            else
            {
                cout << words2[j] << " ";
            }
            i = x;
            j = y;
        }

        while (i < words1.size())
        {
            cout << words1[i] << ' ';
            i++;
        }
        while (j < words2.size())
        {
            cout << words2[j] << " ";
            j++;
        }

        cout << "." << endl;
        getline(cin, s);

        if (s == ".")
            break;
    }

    return 0;
}