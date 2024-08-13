#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <thread>
#include <cmath>
#include <climits>
#include <limits>

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

    int n;
    cin >> n;
    vpii temp;

    for (int i = 0; i < n; i++)
    {
        int l, h;
        cin >> l >> h;
        temp.pb({l, h});
    }

    sort(temp.begin(), temp.end());

    int front = temp[0].first;
    int back = temp[0].second;
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        if (temp[i].first > back)
        {
            ans++;
            front = temp[i].first;
            back = temp[i].second;
        }
        else
        {
            front = max(front, temp[i].first);
            back = min(back, temp[i].second);
        }
    }
    ans++;

    cout << ans << endl;
}