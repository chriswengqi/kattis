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

vi facs{1};

int perm(vi &arr)
{
    if (facs.size() == 1)
    {
        for (int i = 1; i <= 8; i++)
        {
            facs.pb(facs.back() * i);
        }
    }

    int ans = facs[arr.size()];
    vi same;
    int curr = arr[0];
    int ttl = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == curr)
        {
            ttl++;
        }
        else
        {
            same.pb(ttl);
            curr = arr[i];
            ttl = 1;
        }
    }
    same.pb(ttl);
    for (int a : same)
    {
        ans /= facs[a];
    }
    return ans;
};

void solve()
{
    int s;
    cin >> s;
    vi arr;
    int n = s;
    while (s > 0)
    {
        arr.pb(s % 10);
        s /= 10;
    }
    sort(arr.begin(), arr.end());
    int final_ans = 0;
    vi stack;
    function<void(int, int)> dfs = [&](int curr, int idx)
    {
        if (curr == n && idx == arr.size())
        {
            int ans = 1;
            vi tmp{stack[0]};
            for (int i = 1; i < arr.size(); i++)
            {
                if (arr[i] == arr[i - 1])
                {
                    tmp.pb(stack[i]);
                }
                else
                {
                    ans *= perm(tmp);
                    tmp = vi{stack[i]};
                }
            }
            ans *= perm(tmp);
            final_ans += ans;
            return;
        }
        if (curr > n || idx == arr.size())
            return;
        int start = (idx == 0 || arr[idx] != arr[idx - 1] ? 0 : stack.back());
        for (int i = start; curr + pow(arr[idx], i) <= n; i++)
        {
            stack.pb(i);
            dfs(curr + pow(arr[idx], i), idx + 1);
            stack.pop_back();
        }
    };

    dfs(0, 0);

    cout << final_ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    TC = 1;

    while (TC--)
    {
        solve();
    }

    return 0;
}