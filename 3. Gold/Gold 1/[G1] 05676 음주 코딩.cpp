#include <iostream>
#include <bit>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Normalize(int v)
{
    if (v == 0)
        return 0;
    return v / abs(v);
}

int SegTree(int start, int end, int idx, int l, int r, vector<int>& x)
{
    if (r < start || end < l)
        return 1;
    if (start <= l && r <= end)
        return x[idx];

    int mid = (l + r) / 2;
    return SegTree(start, end, idx * 2, l, mid, x)
        * SegTree(start, end, idx * 2 + 1, mid + 1, r, x);
}

int main()
{
    FastIO;

    while (true)
    {
        int n, k;
        cin >> n >> k;

        if (cin.eof())
            break;

        int t = bit_ceil((unsigned int)n);

        vector<int> x(t * 2, 1);
        for (int i = 0; i < n; i++)
        {
            int v;
            cin >> v;

            x[t + i] = Normalize(v);
        }
        for (int i = t - 1; i > 0; i--)
            x[i] = x[i * 2] * x[i * 2 + 1];

        string result = "";
        while (k--)
        {
            char c;
            cin >> c;

            if (c == 'C')
            {
                int i, v;
                cin >> i >> v;

                i += t - 1;
                x[i] = Normalize(v);
                while (i > 1)
                {
                    i /= 2;
                    x[i] = x[i * 2] * x[i * 2 + 1];
                }
            }
            else
            {
                int i, j;
                cin >> i >> j;
                i--, j--;

                int mul = SegTree(i, j, 1, 0, t - 1, x);
                result += (mul == 0 ? '0' : (mul > 0 ? '+' : '-'));
            }
        }
        cout << result << '\n';
    }
}