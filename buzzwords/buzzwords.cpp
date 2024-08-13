#include <bits/stdc++.h>

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

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class SuffixArray
{
private:
    vi RA; // rank array

    void countingSort(int k)
    {                                       // O(n)
        int maxi = max(300LL, n);           // up to 255 ASCII chars
        vi c(maxi, 0);                      // clear frequency table
        for (int i = 0; i < n; ++i)         // count the frequency
            ++c[i + k < n ? RA[i + k] : 0]; // of each integer rank
        for (int i = 0, sum = 0; i < maxi; ++i)
        {
            int t = c[i];
            c[i] = sum;
            sum += t;
        }
        vi tempSA(n);
        for (int i = 0; i < n; ++i) // sort SA
            tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
        swap(SA, tempSA); // update SA
    }

    void constructSA()
    { // can go up to 400K chars
        SA.resize(n);
        iota(SA.begin(), SA.end(), 0); // the initial SA
        RA.resize(n);
        for (int i = 0; i < n; ++i)
            RA[i] = T[i]; // initial rankings
        for (int k = 1; k < n; k <<= 1)
        { // repeat log_2 n times
            // this is actually radix sort
            countingSort(k); // sort by 2nd item
            countingSort(0); // stable-sort by 1st item
            vi tempRA(n);
            int r = 0;
            tempRA[SA[0]] = r;          // re-ranking process
            for (int i = 1; i < n; ++i) // compare adj suffixes
                tempRA[SA[i]] =         // same pair => same rank r; otherwise, increase r
                    ((RA[SA[i]] == RA[SA[i - 1]]) && (RA[SA[i] + k] == RA[SA[i - 1] + k])) ? r : ++r;
            swap(RA, tempRA); // update RA
            if (RA[SA[n - 1]] == n - 1)
                break; // nice optimization
        }
    }

    void computeLCP()
    {
        vi Phi(n);
        vi PLCP(n);
        PLCP.resize(n);
        Phi[SA[0]] = -1;            // default value
        for (int i = 1; i < n; ++i) // compute Phi in O(n)
            Phi[SA[i]] = SA[i - 1]; // remember prev suffix
        for (int i = 0, L = 0; i < n; ++i)
        { // compute PLCP in O(n)
            if (Phi[i] == -1)
            {
                PLCP[i] = 0;
                continue;
            } // special case
            while ((i + L < n) && (Phi[i] + L < n) && (T[i + L] == T[Phi[i] + L]))
                ++L; // L incr max n times
            PLCP[i] = L;
            L = max(L - 1, 0LL); // L dec max n times
        }
        LCP.resize(n);
        for (int i = 0; i < n; ++i) // compute LCP in O(n)
            LCP[i] = PLCP[SA[i]];   // restore PLCP
    }

public:
    const string T; // the input string
    const int n;    // the length of T
    vi SA;          // Suffix Array
    vi LCP;         // of adj sorted suffixes

    SuffixArray(string initialT, const int _n) : T(initialT), n(_n)
    {
        constructSA(); // O(n log n)
        computeLCP();  // O(n)
    }

    pii stringMatching(string P)
    {                           // in O(m log n)
        int m = P.size();       // usually, m < n
        int lo = 0, hi = n - 1; // range = [0..n-1]
        while (lo < hi)
        {                                         // find lower bound
            int mid = (lo + hi) / 2;              // this is round down
            int res = T.compare(SA[mid], m, P);   // P in suffix SA[mid]?
            (res >= 0) ? hi = mid : lo = mid + 1; // notice the >= sign
        }
        if (T.compare(SA[lo], m, P) != 0)
            return {-1, -1}; // if not found
        pii ans;
        ans.first = lo;
        hi = n - 1; // range = [lo..n-1]
        while (lo < hi)
        { // now find upper bound
            int mid = (lo + hi) / 2;
            int res = T.compare(SA[mid], m, P);
            (res > 0) ? hi = mid : lo = mid + 1; // notice the > sign
        }
        if (T.compare(SA[hi], m, P) != 0)
            --hi; // special case
        ans.second = hi;
        return ans; // returns (lb, ub)
    }               // where P is found

    vi matches(string P)
    {
        int length = P.size();
        auto [lb, ub] = stringMatching(P);
        vi res;
        if (!(lb == -1 && ub == -1))
        {
            for (int i = lb; i <= ub; i++)
            {
                if (SA[i] + length < n)
                    res.pb(SA[i]);
            }
        }
        return res;
    }

    pii LRS()
    { // (LRS length, index)
        int idx = 0, maxLCP = -1;
        for (int i = 1; i < n; ++i) // O(n), start from i = 1
            if (LCP[i] > maxLCP)
                maxLCP = LCP[i], idx = i;
        return {maxLCP, idx};
    }

    pii LCS(int split_idx)
    { // (LCS length, index)
        int idx = 0, maxLCP = -1;
        for (int i = 1; i < n; ++i)
        { // O(n), start from i = 1
            // if suffix SA[i] and suffix SA[i-1] came from the same string, skip
            if ((SA[i] < split_idx) == (SA[i - 1] < split_idx))
                continue;
            if (LCP[i] > maxLCP)
                maxLCP = LCP[i], idx = i;
        }
        return {maxLCP, idx};
    }
};
void solve(string ss)
{
    string s = "";
    for (char c : ss)
    {
        if (c != ' ' && int(c) != 13)
        {
            s.pb(c);
        }
    }

    if (s == "")
        return;
    s.pb('$');

    SuffixArray sf(s, s.size());
    for (int i = 1; i <= s.size(); i++)
    { // 0, 1, 2
        int maxx = 0;
        for (int j = 0; j <= s.size() - i; j++)
        {
            int curr = 0;
            auto [lb, ub] = sf.stringMatching(s.substr(j, i));
            for (int k = lb; k <= ub; k++)
            {
                // debug(sf.SA[k]);
                // curr += (sf.SA[k] + i <= s.size() ? 1 : 0);
                curr++;
            }
            maxx = max(maxx, curr);
        }
        if (maxx > 1)
        {
            cout << maxx << '\n';
        }
        else
        {
            cout << '\n';
            return;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    while (getline(cin, s))
    {
        solve(s);
    }

    return 0;
}