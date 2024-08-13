#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        int s;
        cin >> s;
        if (i % k == 0)
        {
            cout << s << " ";
        }
    }
    cout << endl;

    return 0;
}
