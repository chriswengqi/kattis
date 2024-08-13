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
    long N, K;
    cin >> N >> K;
    N--;
    long div = N / K;

    long ans = min(N, K + 1 + abs(K * div - N));

    cout << ans << endl;
}