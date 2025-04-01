#include <iostream>
#include <bit>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct JH
{
    array<int, 2> jh;

    friend JH operator+(const JH& a, const JH& b)
    {
        return { a.jh[0] + b.jh[0],a.jh[1] + b.jh[1] };
    }
};

JH JHlize(int x)
{
    bool isJ = (x % 2 == 0);
    return { isJ,!isJ };
}

JH SegTree(int start, int end, int idx, int l, int r, vector<JH>& a)
{
    if (r < start || end < l)
        return { 0,0 };
    if (start <= l && r <= end)
        return a[idx];

    int mid = (l + r) / 2;
    return SegTree(start, end, idx * 2, l, mid, a)
        + SegTree(start, end, idx * 2 + 1, mid + 1, r, a);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int t = bit_ceil((unsigned)n);
    vector<JH> a(t * 2, { 0,0 });
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        a[t + i] = JHlize(x);
    }
    for (int i = t - 1; i > 0; i--)
        a[i] = a[i * 2] + a[i * 2 + 1];

    int m;
    cin >> m;

    while (m--)
    {
        int c;
        cin >> c;

        if (c == 1)
        {
            int i, x;
            cin >> i >> x;

            i += t - 1;
            a[i] = JHlize(x);
            while (i > 1)
            {
                i /= 2;
                a[i] = a[i * 2] + a[i * 2 + 1];
            }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--, r--;

            JH result = SegTree(l, r, 1, 0, t - 1, a);
            cout << result.jh[c - 2] << '\n';;
        }
    }
}