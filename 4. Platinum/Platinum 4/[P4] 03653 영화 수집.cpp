#include <iostream>
#include <vector>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Seg
{
    int n, t;
    vector<int> tree;

    Seg(int n) : n(n)
    {
        t = bit_ceil(1u * n);
        tree.resize(t * 2, 0);
    }
    void Init()
    {
        for (int i = t - 1; i >= 1; i--)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    void Update(int i, int v)
    {
        i += t;
        tree[i] += v;

        while (i > 1)
        {
            i /= 2;
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
    int Sum(int s, int e) { return Sum(s, e, 0, t - 1, 1); }
    int Sum(int s, int e, int l, int r, int i)
    {
        if (r < s || e < l)
            return 0;
        if (s <= l && r <= e)
            return tree[i];

        int m = (l + r) / 2;
        int lSum = Sum(s, e, l, m, i * 2);
        int rSum = Sum(s, e, m + 1, r, i * 2 + 1);
        return lSum + rSum;
    }
};

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, m;
        cin >> n >> m;

        Seg seg(n + m);
        vector<int> idx(n);
        for (int i = 0; i < n; i++)
            seg.tree[seg.t + i] = 1, idx[i] = n - 1 - i;
        seg.Init();

        for (int q = 0; q < m; q++)
        {
            int i;
            cin >> i;
            i--;

            int result = seg.Sum(idx[i] + 1, n + q - 1);
            cout << result << ' ';

            seg.Update(idx[i], -1);
            idx[i] = n + q;
            seg.Update(idx[i], 1);
        }
        cout << '\n';
    }
}