#include <bits/stdc++.h>
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
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int k, m, n;
  cin >> k >> m >> n;

  int left = 0;
  int right = m - 1;

  while (right < k)
  {
    left += m + n;
    right += m + n;
  }

  // cout << left << " " << right << endl;

  if (left <= k && k <= right)
  {
    cout << "Barb" << endl;
  }
  else
  {
    cout << "Alex" << endl;
  }

  return 0;
}
