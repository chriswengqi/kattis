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

unordered_map<int, int> dic;

int collatz(int i)
{
    if (dic.find(i) != dic.end())
        return dic[i];
    if (i == 1)
        return 0;

    else
    {
        int ans = 0;
        if (i % 2 == 0)
            ans = 1 + collatz(i / 2);
        else
            ans = 1 + collatz(3 * i + 1);
        dic[i] = ans;
        return ans;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    cin >> A >> B;

    while (A != 0 && B != 0)
    {
        int val1 = collatz(A);

        cin >> A >> B;
    }
}
