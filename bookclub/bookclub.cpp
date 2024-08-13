#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vi match, vis; // global variables
vector<vi> AL;

int Aug(int L)
{
    if (vis[L])
        return 0; // L visited, return 0
    vis[L] = 1;
    for (auto &R : AL[L])
        if ((match[R] == -1) || Aug(match[R]))
        {
            match[R] = L; // flip status
            return 1;     // found 1 matching
        }
    return 0; // no matching
}

bool isprime(int v)
{
    int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for (int i = 0; i < 10; ++i)
        if (primes[i] == v)
            return true;
    return false;
}

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int V = n * 2;
    int Vleft = n;
    AL.assign(V, {});

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        AL[a].pb(b + n);
    }

    unordered_set<int> freeV;
    for (int L = 0; L < Vleft; ++L)
        freeV.insert(L); // initial assumption
    match.assign(V, -1);
    int MCBM = 0;
    // Greedy pre-processing for trivial Augmenting Paths
    // try commenting versus un-commenting this for-loop
    for (int L = 0; L < Vleft; ++L)
    { // O(V+E)
        vi candidates;
        for (auto &R : AL[L])
            if (match[R] == -1)
                candidates.push_back(R);
        if ((int)candidates.size() > 0)
        {
            ++MCBM;
            freeV.erase(L);                          // L is matched
            int a = rand() % (int)candidates.size(); // randomize this
            match[candidates[a]] = L;
        }
    } // for each free vertex
    for (auto &f : freeV)
    {                         // (in random order)
        vis.assign(Vleft, 0); // reset first
        MCBM += Aug(f);       // try to match f
    }
    cout << (MCBM == n ? "YES" : "NO") << endl;

    return 0;
}