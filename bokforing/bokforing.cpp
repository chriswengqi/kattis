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

    int n, k;
    cin >> n >> k;

    int set = 0;
    int settime = 0;
    vector<pii> arr(n + 1, {0, -1});
    for (int i = 0; i < k; i++)
    {
        string action;
        cin >> action;
        if (action == "SET")
        {
            int a, b;
            cin >> a >> b;
            arr[a] = {b, i};
        }
        else if (action == "PRINT")
        {
            int a;
            cin >> a;
            if (settime > arr[a].second)
            {
                cout << set << endl;
            }
            else
            {
                cout << arr[a].first << endl;
            }
        }
        else
        {
            int a;
            cin >> a;
            set = a;
            settime = i;
        }
    }
    return 0;
}
