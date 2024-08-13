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

void solve()
{
  int l, n;
  cin >> l >> n;

  int maxx = 0;
  int minn = 0;

  for (int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    maxx = max(maxx, max(l - k, k));
    minn = max(minn, min(k, l - k));
  }

  cout << minn << " " << maxx << endl;
}

int main()
{

  int TC;
  cin >> TC;
  for (int i = 0; i < TC; i++)
  {
    solve();
  }
}