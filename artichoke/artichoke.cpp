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

    double p, a, b, c, d;
    int n;
    cin >> p >> a >> b >> c >> d >> n;

    double curr_max = 0;
    double curr_min = 0;
    double decline = 0;

    for (int i = 1; i <= n; i++)
    {
        double price = p * (sin(a * i + b) + cos(c * i + d) + 2);
        if (i == 0)
        {
            curr_max = price;
            curr_min = price;
        }
        else
        {
            if (price > curr_max)
            {
                curr_max = price;
                curr_min = price;
            }

            if (price < curr_min)
                curr_min = price;
            decline = max(decline, curr_max - curr_min);
        }
    }

    cout << fixed << setprecision(10) << decline << endl;
}
