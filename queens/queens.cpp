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

    int N;
    set<int> h;
    set<int> v;
    set<int> d1;
    set<int> d2;
    bool flag = true;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int r, c;
        cin >> r >> c;
        if (h.find(r) != h.end())
            flag = false;
        if (v.find(c) != v.end())
            flag = false;
        if (d1.find(r + c) != d1.end())
            flag = false;
        if (d2.find(r - c) != d2.end())
            flag = false;

        h.insert(r);
        v.insert(c);
        d1.insert(r + c);
        d2.insert(r - c);
    }

    if (flag)
        cout << "CORRECT" << endl;
    else
        cout << "INCORRECT" << endl;

    return 0;
}
