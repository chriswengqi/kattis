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

void rotate(vvi &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n / 2; i++)
    {
        int l = i;
        int r = n - 1 - i;

        for (int j = l; j < r; j++)
        {
            int off = j - l;
            int top = matrix[l][j];
            matrix[l][j] = matrix[r - off][l];
            matrix[r - off][l] = matrix[r][r - off];
            matrix[r][r - off] = matrix[j][r];
            matrix[j][r] = top;
        }
    }
}

int main()
{
    vvi grid(4, vi(4));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> grid[i][j];
        }
    }
    int move;
    cin >> move;

    if (move != 0)
    {
        for (int i = 0; i < 4 - move; i++)
        {
            rotate(grid);
        }
    }

    vvi new_grid(4, vi(4, 0));
    for (int i = 0; i < 4; i++)
    {
        vi new_v;
        bool moved = false;
        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j] == 0)
                continue;
            else if (!moved && new_v.size() > 0 && new_v.back() == grid[i][j])
            {
                new_v.pop_back();
                new_v.push_back(grid[i][j] * 2);
                moved = true;
            }
            else
            {
                new_v.push_back(grid[i][j]);
                moved = false;
            }
        }
        for (int j = 0; j < new_v.size(); j++)
            new_grid[i][j] = new_v[j];
    }

    if (move != 0)
    {
        for (int i = 0; i < move; i++)
        {
            rotate(new_grid);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << new_grid[i][j] << " ";
        }
        cout << endl;
    }
}