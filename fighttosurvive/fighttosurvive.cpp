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
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
typedef tuple<int, int, int> iii;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int s, m;
    cin >> s >> m;
    vi survivors(s);
    priority_queue<pii> pq;
    for (int i = 0; i < s; i++)
    {
        int h;
        cin >> h;
        survivors[i] = h;
        pq.push({h, h});
    }

    int event = 1;
    int e;
    cin >> e;
    priority_queue<pii> ward;
    deque<int> dq;
    deque<iii> recup;
    for (int i = 1; i <= e; i++)
    {
        // heal
        if (i % m == 0 && ward.size() > 0)
        {
            auto [a, b] = ward.top();
            ward.pop();
            pq.push({b / 2, b});
        }
        // back from recup
        if (recup.size() > 0)
        {
            auto [a, b, ev] = recup.front();
            if (ev == i - 2)
            {
                recup.pop_front();
                pq.push({a, b});
            }
        }
        string st;
        cin >> st;
        if (st == "APPROACH")
        {
            int hi;
            cin >> hi;
            dq.push_back(hi);
        }
        else
        {
            int curr = dq.front();
            dq.pop_front();
            while (curr > 0)
            {
                if (pq.size() == 0)
                {
                    cout << "overrun" << endl;
                    return 0;
                }
                auto [a, b] = pq.top();
                pq.pop();
                if (a > curr) // survivor kills zombie with health to spare
                {
                    a -= curr;
                    curr = 0;
                    recup.push_back({a, b, i});
                }
                else
                {
                    curr -= a;
                    ward.push({0, b});
                }
            }
        }
    }

    cout << "success" << endl;

    return 0;
}
