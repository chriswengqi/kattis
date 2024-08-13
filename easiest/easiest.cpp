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

int digit_sum(int n)
{
    int ans = 0;
    while (n != 0)
    {
        ans += n % 10;
        n = n / 10;
    }

    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n != 0)
    {
        int curr = digit_sum(n);
        int multiple = 11;
        while (true)
        {
            if (curr == digit_sum(n * multiple))
            {
                cout << multiple << endl;
                break;
            }
            multiple++;
        }

        cin >> n;
    }

    return 0;
}
