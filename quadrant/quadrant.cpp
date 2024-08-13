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

    int x, y;
    cin >> x >> y;

    int m = x * y;

    if (m > 0)
    {
        if (x > 0)
            cout << 1 << endl;
        else
            cout << 3 << endl;
    }
    else
    {
        if (x > 0)
            cout << 4 << endl;
        else
            cout << 2 << endl;
    }
}