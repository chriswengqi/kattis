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

struct Score
{
    int s{};
    int p{};
    int f{};
    int o{};
    int i{};
};

inline bool compare(const Score &s1, const Score &s2)
{
    if (s1.s == s2.s)
    {
        if (s1.p == s2.p)
        {
            return s1.f < s2.f;
        }
        return s1.p < s2.p;
    }
    return s2.s < s1.s;
}

int main()
{

    int n;
    cin >> n;
    vector<Score> scores(n);
    vector<int> ans(n);
    vector<int> pts{100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (int i = 0; i < n; i++)
    {
        int s, p, f, o;
        cin >> s >> p >> f >> o;
        scores[i] = Score{s, p, f, o, i};
        // cout << scores[i].s << endl;
    }

    sort(scores.begin(), scores.end(), compare);
    vpii final_scores(n);

    for (int i = 0; i < n;)
    {
        int c = 1;
        int s = (i < pts.size() ? pts[i] : 0);
        while (i < n - 1 && scores[i].f == scores[i + 1].f && scores[i].s == scores[i + 1].s && scores[i].p == scores[i + 1].p)
        {
            c++;
            i++;
            if (i < pts.size())
                s += pts[i];
        }
        int avg = ((s + c - 1) / c);
        // cout << i << " " << c << " " << s << endl;
        for (int j = 0; j < c; j++)
        {

            final_scores[i - j] = {avg + scores[i - j].o, scores[i - j].i};
        }
        i++;
    }

    sort(final_scores.begin(), final_scores.end(), [](const pii &a, const pii &b)
         { return a.second < b.second; });

    for (int i = 0; i < n; i++)
    {
        cout << final_scores[i].first << endl;
    }
}