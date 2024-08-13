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
  int TC;
  cin >> TC;

  for (int i = 0; i < TC; i++)
  {
    int n;
    cin >> n;
    vi arr(n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      total += arr[i];
    }

    double avg = (double)total / (double)n;
    int cnt = 0;

    for (int a : arr)
    {
      // cout << a << " " << avg << endl;
      if (a > avg)
      {
        cnt++;
      }
    }

    double pctg = (double)cnt * 100 / (double)n;
    cout << setprecision(3) << fixed << pctg << '%' << endl;
  }

  return 0;
}
