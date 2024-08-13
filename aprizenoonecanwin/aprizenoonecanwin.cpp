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

  int n, x;
  cin >> n >> x;
  vi arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int ans = 1;

  sort(arr.begin(), arr.end());

  for (int i = n - 2; i >= 0; i--)
  {
    if (arr[i] + arr[i + 1] <= x)
    {
      ans = i + 2;
      break;
    }
  }
  cout << ans << endl;

  return 0;
}
