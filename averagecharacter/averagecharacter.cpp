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
  getline(cin, s);

  int ans = 0;
  for (char x : s)
  {
    ans += x;
  }
  ans = ans / s.size();
  cout << (char)ans << endl;

  return 0;
}
