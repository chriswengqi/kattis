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

bool is_prime(int x)
{
  if (x <= 2)
    return true;
  else
  {
    for (int i = 2; i * i <= x; i++)
    {
      if (x % i == 0)
        return false;
    }
  }
  return true;
}

bool has_cycle(int x)
{
  set<int> s;
  while (x != 1)
  {
    int curr = 0;
    while (x > 0)
    {
      int div = x % 10;
      curr += div * div * div;
      x = x / 10;
    }
    if (s.find(curr) != s.end())
    {
      return true;
    }
    s.insert(curr);

    x = curr;
  }

  return false;
}

int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int k, m;
    cin >> k >> m;

    cout << k << " " << m << " ";
    if (!is_prime(m))
    {
      cout << "NO" << endl;
    }
    else if (has_cycle(m))
    {
      cout << "NO" << endl;
    }
    else
    {
      cout << "YES" << endl;
    }
  }
}