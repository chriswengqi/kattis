#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <thread>
#include <cmath>
#include <climits>
#include <limits>
#include <unordered_map>

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
  int n, p, m;
  cin >> n >> p >> m;

  unordered_map<string, int> dic;

  for (int i = 0; i < n; i++)
  {
    string name;
    cin >> name;
    dic[name] = 0;
  }
  bool flag = false;
  for (int i = 0; i < m; i++)
  {
    string name;
    cin >> name;
    int pts;
    cin >> pts;
    if (dic[name] == -1)
    {
      continue;
    }

    dic[name] += pts;
    if (dic[name] >= p)
    {
      flag = true;
      cout << name << " wins!" << endl;
      dic[name] = -1;
    }
  }

  if (!flag)
  {
    cout << "No winner!" << endl;
  }
}