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

    int n, m;
    cin >> n >> m;
    vi arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        char x;
        int ii, jj;
        cin >> x >> ii >> x >> jj;
        if (find(arr.begin(), arr.end(), jj - 1) - arr.begin() < find(arr.begin(), arr.end(), ii - 1) - arr.begin())
        {
            arr.erase(find(arr.begin(), arr.end(), jj - 1));
            arr.insert(find(arr.begin(), arr.end(), ii - 1) + 1, jj - 1);
        }

        // for (int a : arr)
        // {
        //     cout << "T" << a + 1 << " ";
        // }
        // cout << endl;
    }

    for (int a : arr)
    {
        cout << "T" << a + 1 << " ";
    }
    cout << endl;

    return 0;
}
