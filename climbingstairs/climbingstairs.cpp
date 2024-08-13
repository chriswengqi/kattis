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

  int n, r, k;
  cin >> n >> r >> k;

  int curr = 0;
  bool ground = true;

  if (r >= n)
  {
    cout << r + abs(k - r) + k << endl;
    return 0;
  }

  while (true)
  {
    curr += k;
    ground = !ground;

    if (ground && curr + r >= n)
    {
      curr += r;
      break;
    }
    if (!ground && curr + abs(r - k) >= n)
    {
      curr += abs(r - k);
      break;
    }
  }

  cout << curr + r << endl;

  return 0;
}
