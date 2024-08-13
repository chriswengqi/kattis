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

  string s;
  vector<char> arr;
  getline(cin, s);

  for (char x : s)
  {
    if (x == '<')
    {
      arr.pop_back();
    }
    else
    {
      arr.pb(x);
    }
  }

  for (char x : arr)
    cout << x;
  cout << endl;

  return 0;
}
