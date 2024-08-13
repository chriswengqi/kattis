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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<tuple<int, int, string>> st;
    umap<string, pii> dic;
    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        if (s == 0)
        {
            string t;
            int u;
            cin >> t >> u;
            dic[t] = {ctr, u};                // count, infection
            st.insert(make_tuple(u, ctr, t)); // infection, count, name
            ctr--;
        }
        else if (s == 3)
        {
            if (st.size() == 0)
                cout << "The clinic is empty" << endl;
            else
            {
                auto it = st.end();
                it--;
                cout << get<2>(*it) << endl;
            }
        }
        else if (s == 1)
        {
            string t;
            int u;
            cin >> t >> u;
            auto [x, y] = dic[t];
            st.erase(make_tuple(y, x, t));
            st.insert(make_tuple(u + y, x, t));
            dic[t] = {x, u + y};
        }
        else
        {
            string t;
            cin >> t;
            auto [x, y] = dic[t];
            st.erase(make_tuple(y, x, t));
        }
    }

    return 0;
}