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

    int n;
    cin >> n;
    vi arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    double minn = 1;

    for (int i = 1; i <= n; i++)
    {
        if (arr[i - 1] > i)
        {
            cout << "impossible" << endl;
            return 0;
        }
        minn = min(minn, (double)arr[i - 1] / (double)i);
    }

    cout << minn << endl;

    return 0;
}
