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
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        map<int, int> dic;
        int a = 2, b = 3;
        dic[a % K] = a;
        dic[b % K] = b;
        int ctr = 4;
        while (true)
        {
            int c = (a + b) % K;
            if (dic.find(c) != dic.end())
            {
                cout << dic[c] << endl;
                break;
            }
            else
            {
                dic[c] = ctr;
                ctr++;
                a = b;
                b = c;
            }
        }
    }
}