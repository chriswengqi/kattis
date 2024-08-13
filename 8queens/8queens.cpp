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

    vector<string> arr(8);

    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i];
    }

    set<int> x;
    set<int> y;
    set<int> d1;
    set<int> d2;
    int ans = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (arr[i][j] == '*')
            {
                if (x.find(i) != x.end() || y.find(j) != y.end() || d1.find(i - j) != d1.end() || d2.find(i + j) != d2.end())
                {
                    cout << "invalid" << endl;
                    return 0;
                }

                x.insert(i);
                y.insert(j);
                d1.insert(i - j);
                d2.insert(i + j);
                ans++;
            }
        }
    }
    if (ans != 8)
    {
        cout << "invalid" << endl;
    }
    else
        cout << "valid" << endl;
    return 0;
}
