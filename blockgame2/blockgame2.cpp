#include <bits/stdc++.h>
#include <algorithm>
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
    ll N, B;

    cin >> N >> B;

    ll GCD = __gcd(N, B);
    vector<ll> steps;
    while (N != GCD && B != GCD)
    {
        if (N >= B)
        {
            steps.pb(N / B);
            N -= (N / B) * B;
        }
        else
        {
            steps.pb(B / N);
            B -= (B / N) * N;
        }
    }

    bool stan = true;

    for (int i = 0; i < steps.size(); i++)
    {
        if (steps[i] == 1)
            stan = !stan;
        else
            break;
    }

    if (stan)
        cout << "win" << endl;
    else
        cout << "lose" << endl;
}
