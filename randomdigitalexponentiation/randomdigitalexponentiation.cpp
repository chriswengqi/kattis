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

int a, b;
string ans = "";
void dfs(int total, int ind, string curr_str)
{
    if (total == b && ind == to_string(a).size())
    {
        ans = curr_str;
        return;
    }
    else if (ind == to_string(a).size() && total != b)
        return;
    // cout << total << " " << ind << " " << curr_str << endl;
    int div = pow(10, ind + 1);
    int div2 = pow(10, ind);

    int curr_val = div2;               // 128 -> 100; 43 -> 40
    int curr_digit = (a % div) / div2; // 128 -> 1; 43 -> 4
    // cout << a << " " << ind << " " << curr_val << " " << curr_digit << endl;

    int i = 0;

    while (true)
    {
        int add = curr_val * pow(curr_digit, i);
        cout << add << endl;
        if ((total + add) % div == b % div)
        {
            dfs(total + add, ind + 1, to_string(i) + " " + curr_str);
        }

        if (total + add > b)
            return;

        i++;

        if (curr_digit == 1 || curr_digit == 0)
            return;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    dfs(0, 0, "");

    cout << ans << endl;

    return 0;
}