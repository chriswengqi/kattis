#include <bits/stdc++.h>
#include <algorithm>
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

    int N;
    cin >> N;

    while (true)
    {
        double bit = 4;
        for (int y = 1970; y <= N; y += 10)
        {
            bit *= 2;
        }
        int i = 0;
        double fac = 0;

        while (true)
        {
            if (fac + log2(i + 1) > bit)
            {
                break;
            }
            fac += log2(i + 1);
            // cout << fac << " " << log2(i + 1) << endl;
            i++;
        }

        cout << i << endl;
        cin >> N;
        if (N == 0)
        {
            break;
        }
    }
}
