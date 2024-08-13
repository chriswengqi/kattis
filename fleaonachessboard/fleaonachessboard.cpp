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

  int S, x, y, dx, dy;

  cin >> S >> x >> y >> dx >> dy;
  while (true)
  {
    if ((S % dx == 0 || S % dy == 0) || dx == dy)
    {
      cout << "The flea cannot escape from black sqaures." << endl;
    }
    else
    {
      bool white = ((x / S) + (y / S)) % 2 == 1 && S % x != 0 && S % y != 0;
      while (!white)
      {
        x += dx;
      }
    }
  }

  return 0;
}
