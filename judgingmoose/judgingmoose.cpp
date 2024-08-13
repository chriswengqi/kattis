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

  int l, r;
  cin >> l >> r;

  int maxx = max(l, r);

  if (maxx == 0)
    cout << "Not a moose" << endl;
  else if (l != r)
    cout << "Odd " << maxx * 2 << endl;
  else
    cout << "Even " << maxx * 2 << endl;
}