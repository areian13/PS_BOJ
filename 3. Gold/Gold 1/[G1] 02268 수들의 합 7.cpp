#include <iostream>
#include <bit>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long SegTree(int start, int end, int idx, int l, int r, vector<long long>& a)
{
    if (r < start || end < l)
        return 0;
    if (start <= l && r <= end)
        return a[idx];

    int mid = (l + r) / 2;
    return SegTree(start, end, idx * 2, l, mid, a)
        + SegTree(start, end, idx * 2 + 1, mid + 1, r, a);
}

int main()
{
    FastIO;

    int n, m;
    cin>> n >> m;

    int t = bit_ceil((unsigned int)n);

    vector<long long> a(t * 2, 0);
    while (m--)
    {
        int c, i, k;
        cin>> c >> i >> k;

        if (c == 0)
        {
            i--, k--;

            if (i > k)
                swap(i, k);

            long long result = SegTree(i, k, 1, 0, t - 1, a);
            cout << result << '\n';
        }
        else
        {
            i += t - 1;
            a[i] = k;
            while (i > 1)
            {
                i /= 2;
                a[i] = a[i * 2] + a[i * 2 + 1];
            }
        }
    }
}