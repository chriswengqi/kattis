#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        int n;
        cin >> n;
        priority_queue<pii, vector<pii>, greater<pii>> ask;
        priority_queue<pii> bid;
        int sp = -1;
        for (int i = 0; i < n; i++)
        {
            string action, _;
            int q, p;
            cin >> action >> q >> _ >> _ >> p;
            int curr_sp = 1e9;

            if (action == "buy")
            {

                while (ask.size() > 0 && p >= ask.top().first && q > 0)
                {
                    pii curr = ask.top();
                    ask.pop();
                    if (q >= curr.second)
                    {
                        q -= curr.second;
                    }
                    else
                    {
                        q = 0;
                        ask.push(mp(p, curr.second - q));
                    }
                    if (curr_sp == 1e9)
                        curr_sp = curr.first;
                }
                if (q > 0)
                {
                    bid.push(mp(p, q));
                }
            }
            if (action == "sell")
            {
                while (bid.size() > 0 && p <= bid.top().first && q > 0)
                {
                    pii curr = bid.top();
                    bid.pop();
                    if (q >= curr.second)
                    {
                        q -= curr.second;
                    }
                    else
                    {
                        q = 0;
                        bid.push(mp(p, curr.second - q));
                    }
                    if (curr_sp == 1e9)
                        curr_sp = p;
                }
                if (q > 0)
                {
                    ask.push(mp(p, q));
                }
            }
            sp = curr_sp == 1e9 ? sp : curr_sp;

            // if (ask.size() > 0)
            // {
            //     cout << "Ask: " << ask.top().first << " " << ask.top().second << endl;
            // }
            // if (bid.size() > 0)
            // {
            //     cout << "Bid: " << bid.top().first << " " << bid.top().second << endl;
            // }

            if (ask.size() == 0)
                cout << "- ";
            else
                cout << ask.top().first << " ";

            if (bid.size() == 0)
                cout << "- ";
            else
                cout << bid.top().first << " ";

            if (sp == -1)
                cout << "- ";
            else
                cout << sp << " ";

            cout << endl;
        }
    }

    return 0;
}
