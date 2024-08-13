#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <thread>
#include <cmath>
#include <climits>
#include <limits>
#include <iomanip>

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
  double n, k;
  cin >> n >> k;
  double d, s;
  cin >> d >> s;

  double avg = ((d * n) - (s * k)) / double(n - k);

  if (avg > 100 || avg < 0)
  {
    cout << "impossible" << endl;
  }
  else
  {
    cout << fixed << setprecision(10) << avg << endl;
  }
}