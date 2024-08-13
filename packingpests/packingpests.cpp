#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
typedef tuple<int, int, int> iii;

#define pb push_back
#define em emplace
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define INF 1e9
#define LLINF 4e18
#define umap unordered_map
#define uset unordered_set

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void debug(int a)
{
  cout << a << endl;
}

void debug(vi &arr)
{
  for (int a : arr)
  {
    cout << a << " ";
  }
  cout << endl;
}

void debug(vvi &grid)
{
  for (vi row : grid)
  {
    for (int a : row)
    {
      cout << a << " ";
    }
    cout << endl;
  }
}

void debug(string s)
{
  cout << s << endl;
}

void solve()
{
  int n;
  cin >> n;
  vvi grid(n, vi(n, 2));
  debug(grid);
}

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;
  vi arr(n);
  vi colors(n);

  for (int i = 0; i < n; i++)
    cin >> colors[i] >> arr[i];

  vi curr_colors(k, 0);
  vi best(k, -1);
  vi best_ind(k, -1);
  int curr = 0;
  vi ans(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (curr_colors[colors[i] - 1] == 0)
    {
      curr_colors[colors[i] - 1] = 1;
      curr++;
    }
    if (best[colors[i] - 1] < arr[i])
    {
      best[colors[i] - 1] = arr[i];
      best_ind[colors[i] - 1] = i;
    }

    // debug(best);
    // debug(best_ind);

    if (curr == k)
    {
      for (int a : best_ind)
      {
        ans[a] = 1;
      }
      best.assign(k, -1);
      best_ind.assign(k, -1);
      curr_colors.assign(k, 0);
      curr = 0;
    }
  }

  for (int a : ans)
  {
    cout << (a == 1 ? 'O' : 'X');
  }
  cout << endl;

  return 0;
}