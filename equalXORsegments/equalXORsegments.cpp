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

void solve()
{
    int n, k;
    cin >> n >> k;
    vi arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    umap<int, set<int>> dic;
    for (int i = 1; i <= n; i++)
    {
        arr[i] ^= arr[i - 1];
        if (!dic.count(arr[i]))
            dic[arr[i]] = set<int>();
        dic[arr[i]].insert(i);
    }

    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        if (arr[r] == arr[l - 1])
        {
            cout << "YES" << endl;
        }
        else // l - 1 < idx_arr[r] < idx_(arr[l - 1]) < r
        {
            int right = arr[r];
            int left = arr[l - 1];
            if (dic.count(right))
            {
                auto num = dic[right].lower_bound(l);
                if (num != dic[right].end() && *num < r)
                {

                    if (dic.count(left))
                    {
                        auto num2 = dic[left].lower_bound(*num);
                        if (num2 != dic[left].end() && *num2 < r)
                        {
                            cout << "YES" << endl;
                            continue;
                        }
                    }
                }
            }
            cout << "NO" << endl;
        }
    }

    cout << endl;
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