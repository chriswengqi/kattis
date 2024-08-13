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
    vi chars(26, 0);
    vi solved(26, 0);
    int ttl = 0;
    while (n != -1)
    {
        char a;
        string b;
        cin >> a >> b;

        if (b == "right")
        {
            chars[a - 'A'] += n;
            solved[a - 'A']++;
        }
        else
        {
            chars[a - 'A'] += 20;
        }

        cin >> n;
    }
    int time = 0;
    for (int i = 0; i < 26; i++)
    {
        if (solved[i] == 1)
        {
            time += chars[i];
            ttl++;
        }
    }

    cout << ttl << " " << time << endl;
    return 0;
}
