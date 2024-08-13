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

vector<string> tokenize(string s, string del = " ")
{
    int start, end = -1 * del.size();
    vector<string> ans;
    do
    {
        start = end + del.size();
        end = s.find(del, start);
        ans.pb(s.substr(start, end - start));
    } while (end != -1);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;

    if (s1 == s2)
    {
        cout << "24:00:00" << endl;
        return 0;
    }

    vector<string> v1 = tokenize(s1, ":");
    vector<string> v2 = tokenize(s2, ":");

    // for (int i = 0; i <= 2; i++)
    // {
    //     cout << v1[i] << endl;
    // }

    vector<int> ans;
    int carry = 0;

    for (int i = 2; i >= 0; i--)
    {
        int x = stoi(v1[i]);
        int y = stoi(v2[i]);
        if (x > y + carry)
        {
            int offset = (i != 0) ? 60 : 24;
            ans.pb(offset + y - x + carry);
            carry = -1;
        }
        else
        {
            ans.pb(y - x + carry);
            carry = 0;
        }
    }

    for (int i = 2; i >= 0; i--)
    {
        if (ans[i] < 10)
        {
            cout << "0" << ans[i];
        }
        else
        {
            cout << ans[i];
        }

        if (i != 0)
            cout << ":";
    }
    cout << endl;
}
