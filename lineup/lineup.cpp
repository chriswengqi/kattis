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
    int N;
    cin >> N;
    vector<string> vs;
    int up = 0;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        vs.pb(s);
    }

    for (int i = 1; i < N; i++)
    {
        if (i == 1)
        {
            if (vs[i].compare(vs[i - 1]) < 0)
            {
                up = -1;
            }
            else
            {
                up = 1;
            }
        }
        else
        {
            if (up == 1 && vs[i].compare(vs[i - 1]) < 0)
                up = 0;
            else if (up == -1 && vs[i].compare(vs[i - 1]) > 0)
                up = 0;
        }
    }

    if (up == 0)
        cout << "NEITHER" << endl;
    else if (up == -1)
        cout << "DECREASING" << endl;
    else
        cout << "INCREASING" << endl;
}