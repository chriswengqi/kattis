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
  int curr = 0;
  int side = 1;
  int ans = 0;
  while (curr + side * side <= n)
  {
    curr += side * side;
    side += 2;
    ans++;
  }

  cout << ans << endl;
}