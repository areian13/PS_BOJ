#include <iostream>
#include <bit>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int SegTree(int start, int end, int idx, int l, int r, vector<int>& arr)
{
    if (end < l || r < start)
        return INT_MAX;
    if (start <= l && r <= end)
        return arr[idx];

    int mid = (l + r) / 2;
    return min(SegTree(start, end, idx * 2, l, mid, arr),
        SegTree(start, end, idx * 2 + 1, mid + 1, r, arr));
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int t = bit_ceil((unsigned int)n);

    vector<int> arr(t * 2, INT_MAX);
    for (int i = 0; i < n; i++)
        cin >> arr[t + i];
    for (int i = t - 1; i > 0; i--)
        arr[i] = min(arr[i * 2], arr[i * 2 + 1]);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        int result = SegTree(a, b, 1, 0, t - 1, arr);
        cout << result << '\n';
    }
}