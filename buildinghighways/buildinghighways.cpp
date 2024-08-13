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
  vi arr(n);
  int minn = 1e9 + 1;
  int minn2 = 1e9 + 2;
  for (auto &a : arr)
  {
    cin >> a;
  }
  sort(arr.begin(), arr.end());
  ll ans = 0;

  for (int i = 1; i < n; i++)
  {
    ans += arr[i] + arr[0];
  }

  cout << ans << endl;
}