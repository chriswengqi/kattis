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
  int n;
  cin >> n;
  vi xs(n);
  vi ys(n);

  for (int i = 0; i < n; i++)
  {
    cin >> xs[i];
    cin >> ys[i];
  }

  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());

  ll ans = 0;

  for (int i = 1; i <= n; i++)
  {
    ans += abs(xs[i - 1] - i);
    ans += abs(ys[i - 1] - i);
  }
  cout << ans << endl;
  return 0;
}
