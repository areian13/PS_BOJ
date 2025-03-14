#include <iostream>
#include <bit>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long SegTree(int s, int e, int l, int r, int i,
    vector<long long>& arr)
{
    if (r < s || e < l)
        return 0;
    if (s <= l && r <= e)
        return arr[i];

    int m = (l + r) / 2;
    long long lSeg = SegTree(s, e, l, m, i * 2, arr);
    long long rSeg = SegTree(s, e, m + 1, r, i * 2 + 1, arr);
    return lSeg + rSeg;
}

int main()
{
    FastIO;

    int n, q;
    cin >> n >> q;

    int k = bit_ceil((unsigned int)n);
    vector<long long> arr(k * 2, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[k + i];

    for (int i = k - 1; i >= 1; i--)
        arr[i] = arr[i * 2] + arr[i * 2 + 1];

    for (int t = 1; t <= q; t++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x--, y--;

        if (x > y)
            swap(x, y);

        long long result = SegTree(x, y, 0, k - 1, 1, arr);
        cout << result << '\n';

        a += k - 1;
        arr[a] = b;
        while (a > 1)
        {
            a /= 2;
            arr[a] = arr[a * 2] + arr[a * 2 + 1];
        }
    }
}