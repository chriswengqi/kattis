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

    int a, b, c;

    cin >> a >> b >> c;

    while (a != 0 && b != 0 && c != 0)
    {
        vector<int> arr{a, b, c};
        sort(arr.begin(), arr.end());
        if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
        {
            cout << "right" << endl;
        }
        else
        {
            cout << "wrong" << endl;
        }
        cin >> a >> b >> c;
    }

    return 0;
}
