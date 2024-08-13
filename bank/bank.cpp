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

bool comparefn(pii a, pii b)
{
  if (a.first == b.first)
    return a.second > b.second;
  return a.first < b.first;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, T;

  cin >> N >> T;
  vector<pii> arr(N);
  int time = 0;
  for (int i = 0; i < N; i++)
  {
    int c, t;
    cin >> c >> t;
    arr[i] = mp(t, c);
  }

  ll ans = 0;

  sort(arr.begin(), arr.end(), comparefn);

  for (pii p : arr)
  {

    int t = p.first;
    int c = p.second;

    if (t >= time)
    {
      ans += c;
      time++;
    }
    if (time >= T)
      break;
  }

  cout << ans << endl;

  return 0;
}
