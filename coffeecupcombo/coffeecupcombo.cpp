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
  vector<char> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int ans = 0;
  int cups = 0;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] == '1')
    {
      ans++;
      cups = 2;
    }
    else
    {
      if (cups > 0)
      {
        cups--;
        ans++;
      }
    }
  }

  cout << ans << endl;
}