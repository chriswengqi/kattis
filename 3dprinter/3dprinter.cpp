#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int pwr = 1;
    int ctr = 0;

    while (pwr < n)
    {
        pwr *= 2;
        ctr++;
    }

    cout << ctr + 1 << endl;
}
