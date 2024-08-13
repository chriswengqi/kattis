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
  vi ans(6);

  for (int i = 0; i < 6; i++)
  {
    cin >> ans[i];
  }

  int m;
  cin >> m;
  int _;
  cin >> _;
  vi t1;

  for (int i = 0; i < 6; i++)
  {
    for (int j = i + 1; j < 6; j++)
    {
      for (int k = j + 1; k < 6; k++)
      {
        if (ans[i] + ans[j] + ans[k] == m)
        {
          t1 = {ans[i], ans[j], ans[k]};
          break;
        }
      }
    }
  }
  vi t2;

  for (int i = 0; i < 6; i++)
  {
    if (find(t1.begin(), t1.end(), ans[i]) == t1.end())
    {
      t2.pb(ans[i]);
    }
  }

  sort(t1.begin(), t1.end(), greater<int>());
  sort(t2.begin(), t2.end(), greater<int>());

  for (int a : t1)
  {
    cout << a << " ";
  }

  for (int b : t2)
  {
    cout << b << " ";
  }

  cout << endl;

  return 0;
}
