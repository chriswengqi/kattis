#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <thread>
#include <cmath>
#include <climits>
#include <limits>

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

    int n;
    cin >> n;
    vi days(n);

    for (int i = 0; i < n; i++)
    {
        cin >> days[i];
    }

    int ans = 0;
    int minn = 1e9;

    for (int i = 0; i < n; i++)
    {
        if (days[i] < minn)
        {
            ans = i;
            minn = days[i];
        }
    }

    cout << ans << endl;
}