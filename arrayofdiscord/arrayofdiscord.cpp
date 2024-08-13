#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
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

    int n;
    cin >> n;
    vs arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool flag = true;

    for (int i = 1; i < n && flag; i++)
    {
        if (arr[i].size() > arr[i - 1].size())
            continue;
        else
        {
            string front = arr[i - 1];
            string back = arr[i];

            if (front == "1" && back == "9")
            {
                arr[i] = "0";
                flag = false;
            }

            if (front[0] <= back[0])
            {
                string flip_front = front;
                string flip_back = back;
                flip_front[0] = min('9', char(back[0] + 1));
                if (flip_front > back)
                {
                    arr[i - 1] = flip_front;
                    arr[i] = back;
                    flag = false;
                    continue;
                }
                flip_back[0] = max('1', char(front[0] - 1));
                if (front > flip_back)
                {
                    arr[i - 1] = front;
                    arr[i] = flip_back;
                    flag = false;
                    continue;
                }
            }
        }
    }

    if (!flag)
    {
        for (string s : arr)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "impossible" << endl;
    }

    return 0;
}
