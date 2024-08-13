#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
typedef tuple<int, int, int> iii;

#define pb push_back
#define em emplace
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define INF 1e9
#define LLINF 4e18
#define umap unordered_map
#define uset unordered_set
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
#define debug1(a)                           \
    for (int i = 0; i <= a.size() - 1; i++) \
    cout << a[i] << (i == a.size() - 1 ? '\n' : ' ')
#define debug2(a)                                  \
    for (int i = 0; i <= a.size() - 1; i++)        \
        for (int j = 0; j <= a[0].size() - 1; j++) \
    cout << a[i][j] << (j == a[0].size() - 1 ? '\n' : ' ')

bool ckmin(int &a, int b) { return b < a ? a = b, true : false; }

template <class T>
vector<T> hungarian(const vector<vector<T>> &C)
{
    int J = C.size();
    int W = C[0].size();
    if (J > W)
        swap(J, W);
    assert(J <= W);
    /// job[w] = job assigned to w-th worker, or -1 if no job assigned
    /// note: a W-th worker was added for convenience
    vector<int> job(W + 1, -1);
    vector<T> ys(J), yt(W + 1); /// potentials
    /// -yt[W] will equal the sum of all deltas
    vector<T> answers;
    const T inf = numeric_limits<T>::max();
    for (int j_cur = 0; j_cur < J; ++j_cur)
    { /// assign j_cur-th job
        int w_cur = W;
        job[w_cur] = j_cur;
        /// min reduced cost over edges from Z to worker w
        vector<T> min_to(W + 1, inf);
        vector<int> prv(W + 1, -1); /// previous worker on alternating path
        vector<bool> in_Z(W + 1);   /// whether worker is in Z
        while (job[w_cur] != -1)
        { /// runs at most j_cur + 1 times
            in_Z[w_cur] = true;
            const int j = job[w_cur];
            T delta = inf;
            int w_next;
            for (int w = 0; w < W; ++w)
            {
                if (!in_Z[w])
                {
                    if (ckmin(min_to[w], C[j][w] - ys[j] - yt[w]))
                        prv[w] = w_cur;
                    if (ckmin(delta, min_to[w]))
                        w_next = w;
                }
            }
            /// delta will always be non-negative,
            /// except possibly during the first time this loop runs
            /// if any entries of C[j_cur] are negative
            for (int w = 0; w <= W; ++w)
            {
                if (in_Z[w])
                    ys[job[w]] += delta, yt[w] -= delta;
                else
                    min_to[w] -= delta;
            }
            w_cur = w_next;
        }
        /// update assignments along alternating path
        for (int w; w_cur != -1; w_cur = w)
            job[w_cur] = job[w = prv[w_cur]];
        answers.push_back(-yt[W]);
    }
    return job;
}
signed main()
{
    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> costMatrix;
    costMatrix.resize(n, vector<int>(m, 1e9));
    for (int i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        costMatrix[a - 1][b - 1] = 1000 - c;
    }
    vi ans = hungarian(costMatrix); // array of workers
    int topics = 0;
    int total = 0;

    vi assignments(n, -1);

    for (int x = 0; x < m; x++)
    {

        if (ans[x] != -1 && costMatrix[ans[x]][x] != 1e9)
        {
            total += (1000 - costMatrix[ans[x]][x]);
            assignments[ans[x]] = x;
        }
    }

    for (int a : assignments)
    {
        if (a == -1)
            topics++;
    }

    cout << topics << " " << total << endl;

    return 0;
}
