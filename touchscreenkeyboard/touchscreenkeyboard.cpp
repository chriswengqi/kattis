#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18
unordered_map<char, pii> dic;

int find_dist(char a, char b)
{
    pii i = dic[a];
    pii j = dic[b];

    return abs(i.first - j.first) + abs(i.second - j.second);
}

void solve()
{
    string s;
    int n;
    cin >> s >> n;
    vector<pair<int, string>> arr;

    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        int ans = 0;
        for (int j = 0; j < t.size(); j++)
        {
            ans += find_dist(s[j], t[j]);
        }
        arr.pb({ans, t});
    }
    sort(arr.begin(), arr.end());

    for (auto &[k, v] : arr)
    {
        cout << v << ' ' << k << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vs keyboard = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < keyboard[i].size(); j++)
        {
            dic[keyboard[i][j]] = {i, j};
        }
    }

    int TC;
    cin >> TC;

    while (TC--)
    {
        solve();
    }

    return 0;
}
