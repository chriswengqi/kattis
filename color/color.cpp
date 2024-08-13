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
  int s, c, k;
  cin >> s >> c >> k;

  vi arr(s);
  for (int i = 0; i < s; i++)
  {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  int curr = arr[0];
  int count = 0;
  int ans = 0;

  for (int i = 0; i < s; i++)
  {
    if (arr[i] - curr > k || count == c)
    {
      ans++;
      curr = arr[i];
      count = 0;
    }
    count++;
  }

  cout << ans + 1 << endl;
}