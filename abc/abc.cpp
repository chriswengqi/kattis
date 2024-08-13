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
    vi arr(3);
    for (int i = 0; i < 3; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    char x;
    for (int i = 0; i < 3; i++)
    {
        cin >> x;
        cout << arr[x - 'A'] << " ";
    }
    cout << endl;
    return 0;
}
