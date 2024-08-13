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

int mod = 1000000007;

struct modint
{
    int n;
    modint() : n(0) { ; }
    modint(ll m)
    {
        if (m < 0 || mod <= m)
        {
            m %= mod;
            if (m < 0)
                m += mod;
        }
        n = m;
    }
    operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
bool operator<(modint a, modint b) { return a.n < b.n; }
modint operator+=(modint &a, modint b)
{
    a.n += b.n;
    if (a.n >= mod)
        a.n -= mod;
    return a;
}
modint operator-=(modint &a, modint b)
{
    a.n -= b.n;
    if (a.n < 0)
        a.n += mod;
    return a;
}
modint operator*=(modint &a, modint b)
{
    a.n = ((ll)a.n * b.n) % mod;
    return a;
}
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n)
{
    if (n == 0)
        return modint(1);
    modint res = (a * a) ^ (n / 2);
    if (n % 2)
        res = res * a;
    return res;
}

ll inv(ll a, ll p)
{
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint &a, modint b)
{
    a = a / b;
    return a;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int mod = 1e9 + 7;

    int N, K;
    cin >> N >> K;

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    vi times;
    times.pb(D);
    umap<int, int> dic;
    dic[D] = 0;
    int cycle_start = -1;
    int cycle_end = -1;
    for (int i = 1; i <= min(N, C); i++)
    {
        int val = ((A * times.back() + B) % C + 1);
        if (dic.count(val))
        {
            cycle_start = dic[val];
            cycle_end = i - 1;
            break;
        }
        times.pb(val);
        dic[val] = i;
    }
    if (cycle_start == -1) // no cycle, won't worry about TLE
    {
        sort(times.begin(), times.end());
        ll total_time = 0;
        int total = 0;
        ll total_penalty = 0;
        for (int i = 0; i < N; i++)
        {
            if (total_time + times[i] <= K)
            {
                total_time += times[i];
                total++;
                total_penalty = (total_penalty + total_time) % mod;
            }
            else
            {
                break;
            }
        }

        cout << total << ' ' << total_penalty << endl;
    }
    else
    {

        int cycle_size = cycle_end - cycle_start + 1;
        // [0,1,2,3,4,5,6,7,4,5,6,7]
        map<int, int> dic2;
        for (int i = 0; i < cycle_start; i++)
        {
            dic2[times[i]] = 1;
        }
        for (int i = cycle_start; i <= cycle_end; i++)
        {
            if (!dic2.count(times[i]))
            {
                dic2[times[i]] = 0;
            }
            int residue = (N - cycle_start) % cycle_size;
            dic2[times[i]] += (N - cycle_start) / cycle_size + (i - cycle_start < residue ? 1 : 0);
        }
        int total = 0;
        int total_time = 0;
        modint penalty = 0;
        for (auto &[k, v] : dic2)
        {
            // cout << k << " " << v << endl;
            if (total_time + k * v <= K)
            {
                modint curr_v = v;
                total += v;
                penalty += ((modint)total_time * curr_v) + (modint)k * (curr_v * (curr_v + (modint)1) / (modint)2);
                total_time += k * v;
            }
            else
            {
                modint curr_v = (K - total_time) / k;
                total += curr_v;
                penalty += ((modint)total_time * curr_v) + (modint)k * (curr_v * (curr_v + (modint)1) / (modint)2);
                break;
            }
        }

        cout << total << " " << penalty << endl;
    }

    return 0;
}
