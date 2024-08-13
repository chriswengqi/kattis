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

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    for (int i = 0; i < 3; i++)
    {
        int a = 0;
        int b = 0;
        int S;
        cin >> S;
        int rem = (S - 1) % (A + B);
        if (rem < A)
            a++;
        rem = (S - 1) % (C + D);
        if (rem < C)
            b++;

        if (a + b == 2)
            cout << "both" << endl;
        else if (a + b == 1)
            cout << "one" << endl;
        else
            cout << "none" << endl;
    }

    return 0;
}
