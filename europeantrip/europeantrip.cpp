#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

double distance(pdd p1, pdd p2)
{
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    vector<pdd> vertices{{x1, y1}, {x2, y2}, {x3, y3}};

    double epsilon = 1e-6;

    pdd initialGuess{0, 0}; // You can choose any initial guess
    pdd currentGuess = initialGuess;

    while (true)
    {
        double sumX = 0.0, sumY = 0.0;
        double sumDistances = 0.0;

        for (auto vertex : vertices)
        {
            double dist = distance(currentGuess, vertex);
            if (dist > epsilon)
            { // Avoid division by zero
                sumX += (vertex.first - currentGuess.first) / dist;
                sumY += (vertex.second - currentGuess.second) / dist;
                sumDistances += 1.0 / dist;
            }
        }

        pdd nextGuess{sumX / sumDistances, sumY / sumDistances};

        if (distance(currentGuess, nextGuess) < epsilon)
        {
            cout << nextGuess.first << " " << nextGuess.second << endl; // Convergence reached
            break;
        }

        currentGuess = nextGuess;
    }

    return 0;
}
