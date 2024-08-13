#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned int ui;
#define int ui
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
#define sz(x) (int)x.size()
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

vpii directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// int mod = (1LL << 32);

vvi multiply(vvi &matrix1, vvi &matrix2)
{
    assert(matrix1.size() > 0 && matrix2.size() > 0 & matrix1[0].size() == matrix2.size());
    int m = matrix1.size();
    int n = matrix1[0].size();
    int k = matrix2[1].size();
    vvi new_matrix(m, vi(k, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int k = 0; k < n; k++)
            {
                new_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
                // new_matrix[i][j] %= mod;
            }
        }
    }

    return new_matrix;
}

vvi fast_expo(vvi &matrix, int power)
{
    int n = matrix.size();
    vvi curr(n, vi(n, 0));

    for (int i = 0; i < n; i++)
    {
        curr[i][i] = 1;
    }

    while (power > 0)
    {
        if (power & 1)
            curr = multiply(curr, matrix);
        matrix = multiply(matrix, matrix);
        power >>= 1;
    }

    return curr;
}

void print(vvi &mat)
{
    for (vi &v : mat)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << '\n';
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vvi idmx(k + 1, vi(k + 1, 0));

    for (int i = 0; i <= k; i++)
    {
        idmx[i][i] = 1;
    }

    vvi vec(k + 1, vi(1, 1));
    for (int i = 0; i < k; i++)
    {
        cin >> vec[i][0];
    }
    int count = -1;
    vector<vvi> stack;
    vpii temp;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "add")
        {
            string t, u, v;
            cin >> t >> u >> v;
            int tt = stoll(t.substr(1, t.size() - 2));
            int uu = stoll(u.substr(1, u.size() - 2));
            int vv = stoll(v.substr(1, v.size() - 1));
            vvi curr = idmx;
            curr[tt][tt] = 0;
            curr[tt][uu]++;
            curr[tt][vv]++;
            stack.pb(curr);
        }
        else if (s == "addi")
        {

            string t, u, v;
            cin >> t >> u >> v;
            int tt = stoll(t.substr(1, t.size() - 2));
            int uu = stoll(u.substr(1, u.size() - 2));
            int vv = stoll(v);
            vvi curr = idmx;
            curr[tt][tt] = 0;
            curr[tt][uu] = 1;
            curr[tt][k] = vv;
            stack.pb(curr);
        }
        else if (s == "li")
        {
            string t, u;
            cin >> t >> u;
            int tt = stoll(t.substr(1, t.size() - 2));
            int uu = stoll(u);
            vvi curr = idmx;
            curr[tt][tt] = 0;
            curr[tt][k] = uu;
            stack.pb(curr);
        }
        else if (s == "for")
        {
            int c;
            cin >> c;
            temp.pb({stack.size(), c});
        }
        else if (s == "rof")
        {
            vvi curr = idmx;
            int cnt = 0;
            // debug(temp.back().first);
            // debug(stack.size());
            for (int j = temp.back().first; j < stack.size(); j++)
            {
                curr = multiply(stack[j], curr);
                cnt++;
            }
            for (int j = 0; j < cnt; j++)
                stack.pop_back();
            curr = fast_expo(curr, temp.back().second);
            stack.pb(curr);
            temp.pop_back();
        }
        else // move
        {
            string t, u;
            cin >> t >> u;
            int tt = stoll(t.substr(1, t.size() - 2));
            int uu = stoll(u.substr(1, t.size() - 1));
            vvi curr = idmx;
            curr[tt][tt] = 0;
            curr[tt][uu] = 1;
            stack.pb(curr);
        }
    }
    assert(temp.size() == 0);
    // debug(stack.size());
    vvi curr = vec;

    for (int i = 0; i < stack.size(); i++)
    {
        curr = multiply(stack[i], curr);
    }
    for (int i = 0; i < k; i++)
    {
        cout << curr[i][0] << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    TC = 1;

    while (TC--)
    {
        solve();
    }

    return 0;
}