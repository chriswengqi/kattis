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
    int K;
    cin >> K;
    int curr = 1;
    while (curr < K)
    {
        curr *= 2;
    }
    int total = 0;
    int rem = curr;

    while (K > 0)
    {
        while (K < rem)
        {
            rem = rem / 2;
            total++;
        }
        K -= rem;
    }

    cout << curr << " " << total << endl;
}
