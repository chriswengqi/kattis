#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<double, double>> vpdd;
#define pb push_back
#define em emplace
#define mp make_pair
#define IT(i, n) for (int i = 0; i < n; i++)
#define BIGINT 1e18

int merge(vi &arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int invCount = 0;
    int A[n1];
    int B[n2];

    for (int i = 0; i < n1; i++)
    {
        A[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        B[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (A[i] > B[j])
        {
            arr[k] = B[j];
            j++;
            invCount += (n1 - i);
        }
        else
        {
            arr[k] = A[i];
            i++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = A[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = B[j];
        j++;
        k++;
    }

    return invCount;
}

int mergeSort(vi &arr, int l, int r)
{
    int left = 0;
    int right = 0;
    int cross = 0;

    if (l < r)
    {
        int mid = l + (r - l) / 2;
        left = mergeSort(arr, l, mid);
        right = mergeSort(arr, mid + 1, r);
        cross = merge(arr, l, mid, r);
    }

    return left + right + cross;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << mergeSort(arr, 0, n - 1) << endl;

    return 0;
}
