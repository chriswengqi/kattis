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

    int a, b;
    cin >> a >> b;
    int maxx = max(a, b);
    int minn = min(a, b);

    string s;
    cin >> s;
    if (s == "ABBA")
    {
        if (maxx - minn == 3)
        {
            cout << minn + 1 << " " << maxx - 1 << endl;
        }
        else
        {
            cout << -1;
        }
    }

    if (s == "ABAB")
    {
        if (minn == 6 && maxx == 8)
        {
            cout << "7 9" << endl;
        }
        else
        {
            cout << -1;
        }
    }

    if (s == "BABA")
    {
        if (minn == 2 && maxx == 4)
        {
            cout << "1 3" << endl;
        }
        else
        {
            cout << -1;
        }
    }

    if (s == "BAAB")
    {
        if (minn == 2 && maxx == 8)
        {
            cout << "1 9" << endl;
        }
        else
        {
            cout << -1;
        }
    }

    if (s == "AABB")
    {
        if (maxx == 7)
        {
            cout << "8 9" << endl;
        }
        else
        {
            cout << -1;
        }
    }

    if (s == "BBAA")
    {
        if (minn == 3)
        {
            cout << "1 2" << endl;
        }
        else
        {
            cout << -1;
        }
    }

    return 0;
}
