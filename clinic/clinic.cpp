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

void solve()
{
    int n;
    cin >> n;
    vvi grid(n, vi(n, 2));
    debug(grid);
}

int k;

struct Compare
{
    bool operator()(const tuple<int, int, string> &a, const tuple<int, int, string> &b) const
    {
        int priority_a = get<0>(a) - get<1>(a) * k;
        int priority_b = get<0>(b) - get<1>(b) * k;

        if (priority_a != priority_b)
            return priority_a < priority_b;
        else
            return get<2>(a) > get<2>(b); // Compare strings in reverse order (lexicographically)
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> k;
    priority_queue<tuple<int, int, string>, vector<tuple<int, int, string>>, Compare> pq;
    uset<string> removed;

    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        if (s == 1)
        {
            int a, b;
            string t;
            cin >> a >> t >> b;
            pq.push(make_tuple(b, a, t));
        }
        else if (s == 2)
        {
            int t;
            cin >> t;
            if (pq.size() > 0)
            {

                while (removed.count(get<2>(pq.top())))
                {
                    pq.pop();
                }
                cout << get<2>(pq.top()) << endl;
                pq.pop();
            }
            else
            {
                cout << "doctor takes a break" << endl;
            }
        }
        else
        {
            int s;
            string t;
            cin >> s >> t;
            removed.insert(t);
        }
    }

    return 0;
}