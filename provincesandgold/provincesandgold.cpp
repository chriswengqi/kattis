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

    int g, s, c;
    cin >> g >> s >> c;

    int ans = 3 * g + s * 2 + c * 1;

    if (ans >= 8)
    {
        cout << "Province or ";
    }
    else if (ans >= 5)
        cout << "Duchy or ";
    else if (ans >= 2)
        cout << "Estate or ";

    if (ans >= 6)
        cout << "Gold" << endl;
    else if (ans >= 3)
        cout << "Silver" << endl;
    else
        cout << "Copper" << endl;
}