#include <iostream>
#include <bit>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int SegTree(int s, int e, int l, int r, int i, vector<int>& arr)
{
    if (r < s || e < l)
        return 0;
    if (s <= l && r <= e)
        return arr[i];

    int m = (l + r) / 2;
    int lSeg = SegTree(s, e, l, m, i * 2, arr);
    int rSeg = SegTree(s, e, m + 1, r, i * 2 + 1, arr);
    return lSeg + rSeg;
}

int BS(int i, int n, int k, vector<int>& arr)
{
    int s = 0, e = n - 1;
    int result = e;
    while (s <= e)
    {
        int m = (s + e) / 2;
        int sum = SegTree(0, m, 0, k - 1, 1, arr);
        if (sum < i)
            s = m + 1;
        else
        {
            result = m;
            e = m - 1;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int k = bit_ceil((unsigned int)n);
    vector<int> arr(k * 2, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[k + i];

    for (int i = k - 1; i >= 1; i--)
        arr[i] = arr[i * 2] + arr[i * 2 + 1];

    int m;
    cin >> m;

    for (int t = 1; t <= m; t++)
    {
        int q, i;
        cin >> q >> i;

        if (q == 1)
        {
            int a;
            cin >> a;

            i += k - 1;
            arr[i] += a;

            while (i > 1)
            {
                i /= 2;
                arr[i] = arr[i * 2] + arr[i * 2 + 1];
            }
        }
        else
        {
            int result = BS(i, n, k, arr);
            cout << result + 1 << '\n';
        }
    }
}