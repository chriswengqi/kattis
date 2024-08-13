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
    float ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        float x, y;
        cin >> x >> y;
        ans += x * y;
    }
    cout << ans << endl;
}