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

// Trie node (considering only lowercase alphabets)
struct Node
{
    Node *arr[26];
    int freq;
};

// Function to insert a node in the trie
Node *insert(string s, Node *root)
{
    int in;
    Node *cur = root;
    for (int i = 0; i < s.length(); i++)
    {
        in = s[i] - 'a';

        // If there is no node created then create one
        if (cur->arr[in] == NULL)
            cur->arr[in] = new Node();

        // Increase the frequency of the node
        cur->arr[in]->freq++;

        // Move to the next node
        cur = cur->arr[in];
    }

    // Return the updated root
    return root;
}

// Function to return the count of strings
// whose prefix of length k matches with the
// k length prefix of the given string
int find(string s, int k, Node *root)
{
    int in, count = 0;
    Node *cur = root;

    // Traverse the string
    for (int i = 0; i < s.length(); i++)
    {
        in = s[i] - 'a';

        // If there is no node then return 0
        if (cur->arr[in] == NULL)
            return 0;

        // Else traverse to the required node
        cur = cur->arr[in];

        count++;

        // Return the required count
        if (count == k)
            return cur->freq;
    }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<string> s;

    Node *root = new Node();

    for (int i = 0; i < n; i++)
    {
        string c;
        cin >> c;
        cout << find(c, c.size(), root) << endl;
        root = insert(c, root);
    }

    return 0;
}