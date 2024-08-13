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

  int a, b, h;
  cin >> a >> b >> h;

  int curr = 0;
  int ans = 0;

  while (curr + a < h)
  {
    curr += a - b;
    ans++;
  }

  cout << ans + 1 << endl;
}