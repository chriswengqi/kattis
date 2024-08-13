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

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void debug(int a)
{
    cout << a << endl;
}

void debug(vi &arr)
{
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}

void debug(vvi &grid)
{
    for (vi row : grid)
    {
        for (int a : row)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}

void debug(vpii &arr)
{
    for (auto [k, v] : arr)
    {
        cout << k << " " << v << endl;
    }
}

void debug(string s)
{
    cout << s << endl;
}

vi match, vis; // global variables
vector<uset<int>> AL;

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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int V = n * 4;
    int Vleft = n;
    AL.assign(V, {});

    int curr = n;
    umap<int, int> dic;
    umap<int, int> rev_dic;
    vpii arr;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr.pb({a, b});
        if (!dic.count(a + b))
        {
            dic[a + b] = curr;
            rev_dic[curr] = a + b;
            AL[i].insert(curr);
            curr++;
        }
        else
        {
            AL[i].insert(dic[a + b]);
        }

        if (!dic.count(a - b))
        {
            dic[a - b] = curr;
            rev_dic[curr] = a - b;
            AL[i].insert(curr);
            curr++;
        }
        else
        {
            AL[i].insert(dic[a - b]);
        }

        if (!dic.count(a * b))
        {
            dic[a * b] = curr;
            rev_dic[curr] = a * b;
            AL[i].insert(curr);
            curr++;
        }
        else
        {
            AL[i].insert(dic[a * b]);
        }

        // for (int a : AL[i])
        //     cout << a << " ";
        // cout << endl;
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
    // debug(match);
    if (MCBM != n)
    {
        cout << "impossible" << endl;
    }
    else
    {
        vi matches(n);
        for (int i = n; i < 4 * n; i++)
        {
            if (match[i] != -1)
            {
                matches[match[i]] = rev_dic[i];
            }
        }
        // debug(matches);
        for (int i = 0; i < n; i++)
        {
            int front = arr[i].first;
            int back = arr[i].second;
            if (front + back == matches[i])
            {
                cout << front << " + " << back << " = " << matches[i] << endl;
            }
            else if (front - back == matches[i])
            {
                cout << front << " - " << back << " = " << matches[i] << endl;
            }
            else
            {
                cout << front << " * " << back << " = " << matches[i] << endl;
            }
        }
    }

    return 0;
}