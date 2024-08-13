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

    int a, b, c, n;

    cin >> a >> b >> c >> n;
    bool cond = (a > 0 && b > 0 && c > 0 && a + b + c >= n && n >= 3);
    if (cond)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}