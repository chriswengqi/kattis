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
    int N, K;
    cin >> N >> K;
    unordered_map<string, set<int>> dic;
    int ans = 0;

    for (int i = 0; i < K; i++)
    {
        int c1, c2;
        string p1, p2;
        cin >> c1 >> c2 >> p1 >> p2;

        if (p1 == p2)
            ans--;
        if (dic.find(p1) == dic.end())
            dic[p1] = set<int>();
        if (dic.find(p2) == dic.end())
            dic[p2] = set<int>();
        dic[p1].insert(c1);
        dic[p2].insert(c2);
    }
    int twos = 0;
    int ones = 0;
    for (auto &p : dic)
    {
        if (p.second.size() == 2)
        {
            twos++;
        }
        if (p.second.size() == 1)
        {
            ones++;
        }
    }

    ans += twos;
    if (twos + ones == N / 2)
        ans += ones;
    else if (twos == N / 2 - 1)
        ans += 1;

    cout << ans << endl;
}