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

  int N, M;
  cin >> N >> M;
  vi visited(N + 1, 0);
  vvi adj(N + 1, vi());

  for (int i = 0; i < M; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  deque<int> d;
  d.pb(1);

  while (d.size() > 0)
  {
    int curr = d.front();
    d.pop_front();
    visited[curr] = 1;

    for (int v : adj[curr])
    {
      if (visited[v] == 0)
      {
        d.pb(v);
        visited[v] = 1;
      }
    }
  }

  bool all = false;
  for (int i = 1; i <= N; i++)
  {
    if (visited[i] == 0)
    {
      cout << i << endl;
      all = true;
    }
  }
  if (!all)
    cout << "connected" << endl;

  return 0;
}
