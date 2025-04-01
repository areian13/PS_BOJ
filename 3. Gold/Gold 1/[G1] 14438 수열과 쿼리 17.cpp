#include <iostream>
#include <bit>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int SegTree(int start, int end, int idx, int l, int r, vector<int>& a)
{
    if (r < start || end < l)
        return INT_MAX;
    if (start <= l && r <= end)
        return a[idx];

    int mid = (l + r) / 2;
    return min(SegTree(start, end, idx * 2, l, mid, a),
        SegTree(start, end, idx * 2 + 1, mid + 1, r, a));
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int t = bit_ceil((unsigned int)n);

    vector<int> a(t * 2, INT_MAX);
    for (int i = 0; i < n; i++)
        cin >> a[t + i];
    for (int i = t - 1; i > 0; i--)
        a[i] = min(a[i * 2], a[i * 2 + 1]);

    int m;
    cin >> m;

    while (m--)
    {
        int c;
        cin >> c;

        if (c == 1)
        {
            int i, v;
            cin >> i >> v;

            i += t - 1;
            a[i] = v;

            while (i > 1)
            {
                i /= 2;
                a[i] = min(a[i * 2], a[i * 2 + 1]);
            }
        }
        else
        {
            int i, j;
            cin >> i >> j;
            i--, j--;

            int result = SegTree(i, j, 1, 0, t - 1, a);
            cout << result << '\n';
        }
    }
}