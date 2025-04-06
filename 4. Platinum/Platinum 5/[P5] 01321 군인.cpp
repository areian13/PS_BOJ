#include <iostream>
#include <bit>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int SegTree(int v, int s, int e, int i, vector<int>& arr)
{
    if (s == e)
        return s;

    int m = (s + e) / 2;
    if (arr[i * 2] >= v)
        return SegTree(v, s, m, i * 2, arr);
    else
        return SegTree(v - arr[i * 2], m + 1, e, i * 2 + 1, arr);
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
            int result = SegTree(i, 0, k - 1, 1, arr);
            cout << result + 1 << '\n';
        }
    }
}