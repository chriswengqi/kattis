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

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void debug(int a)
{
    cout << a << endl;
}

void debug(vi &arr)
{
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}

void debug(vvi &grid)
{
    for (vi row : grid)
    {
        for (int a : row)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}

void debug(vpii &arr)
{
    for (auto [k, v] : arr)
    {
        cout << k << " " << v << endl;
    }
}

void debug(string s)
{
    cout << s << endl;
}
struct pairhash
{
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const
    {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

int n;
umap<string, int> maps;
uset<string> dic;
vs arr;
string ans = "";

void dfs(string curr, int bitmask)
{
    if (ans != "")
    {
        return;
    }
    if (bitmask == (1 << n) - 1 && ans == "")
    {
        ans = curr;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!((1 << i) & bitmask))
        {
            string new_string = "0";
            new_string[0] = (char)(i + '0');
            string inp = curr + new_string;
            if (!dic.count(inp.substr(inp.size() - 2, 2)))
                dfs(curr + new_string, bitmask | (1 << i));
        }
    }
}
void solve()
{
    maps.clear();
    dic.clear();
    arr.resize(n);
    ans = "";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vi perm(n);
    for (int i = 0; i < n; i++)
    {
        maps[arr[i]] = i;
        perm[i] = i;
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string a, b;
        cin >> a >> b;
        int aa = maps[a];
        int bb = maps[b];
        string str1 = "00";
        string str2 = "00";
        str1[1] = str2[0] = (char)((aa + '0'));
        str1[0] = str2[1] = (char)((bb + '0'));
        dic.insert(str1);
        dic.insert(str2);
    }

    for (int i = 0; i < n; i++)
    {
        string curr = "0";
        curr[0] = '0' + (char)(i);
        dfs(curr, (1 << i));
    }

    if (ans != "")
    {
        for (char c : ans)
        {
            cout << arr[c - '0'] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "You all need therapy." << endl;
    }

    // cout << "You all need therapy." << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n)
    {
        solve();
    }

    return 0;
}