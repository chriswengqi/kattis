// UNSOLVED

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int a = (s[0] == 'D') ? 1 : 0;
    int b = 0;
    int c = 0;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[i - 1])
            c++;
    }
}