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

    int n, m;

    cin >> n >> m;
    string pieces = abs(n - m) == 1 ? "piece" : "pieces";
    if (m >= n)
        cout << "Dr. Chaz will have " << m - n << " " << pieces << " of chicken left over!" << endl;
    else
        cout << "Dr. Chaz needs " << n - m << " more " << pieces << " of chicken!" << endl;
}