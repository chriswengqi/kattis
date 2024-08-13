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

  for (int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    for (int j = 1; j <= 10; j++)
    {
      int curr = 7 * j;
      if (curr % 10 == k % 10)
      {
        if (curr > k)
        {
          cout << -1 << endl;
        }
        else
        {
          cout << j << endl;
        }

        break;
      }
    }
  }
}