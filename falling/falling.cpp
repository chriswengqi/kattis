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
  int n;
  cin >> n;

  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      if (i % 2 + (n / i) % 2 != 1)
      {
        cout << (n / i - i) / 2 << " " << (n / i + i) / 2 << endl;
        return 0;
      }
    }
  }

  cout << "impossible" << endl;
}