#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;

    vector<vpii> graph(10, vpii());

    graph[0] = {{6, 0}, {9, 0}, {8, 1}};
    graph[1] = {{7, 1}};
    graph[2] = {{3, 0}};
    graph[3] = {{2, 0}, {5, 0}, {9, 1}};
    graph[5] = {{3, 0}, {6, 1}, {9, 1}};
    graph[6] = {{0, 0}, {5, -1}, {8, 1}, {9, 0}};
    graph[7] = {{1, -1}};
    graph[8] = {{0, -1}, {6, -1}, {9, -1}};
    graph[9] = {{0, 0}, {3, -1}, {5, -1}, {6, 0}, {8, 1}};

    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i])
        {
            bool flag = false;
            for (auto &[k, v] : graph[int(s[i] - '0')])
            {
                if (k == (int)(t[i] - '0'))
                {
                    if (v == 0)
                    {
                        ans1++;
                        ans2++;
                    }
                    else if (v == 1)
                    {
                        ans1++;
                    }
                    else
                    {
                        ans2++;
                    }
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                cout << "no" << endl;
                return 0;
            }
        }
    }

    cout << (ans1 == 1 && ans2 == 1 ? "yes" : "no") << endl;

    return 0;
}
