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
  vi arr(n);
  unordered_map<int, int> dic;

  int curr_min = n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    if (dic.find(arr[i]) == dic.end())
    {
      dic[arr[i]] = i;
    }
    else
    {
      curr_min = min(curr_min, i - dic[arr[i]]);
      dic[arr[i]] = i;
    }
  }

  cout << curr_min << endl;

  return 0;
}
