#include <iostream>
#include <bit>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct SegTree
{
    int n, t;
    vector<int> tree, lazy;

    SegTree(vector<int>& a)
    {
        n = a.size();
        t = bit_ceil((unsigned int)n);

        tree.resize(t * 2, 0);
        lazy.resize(t * 2, 0);
        for (int i = 0; i < n; i++)
            tree[t + i] = a[i];
        for (int i = t - 1; i >= 1; i--)
            tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
    }

    void Propagate(int l, int r, int i)
    {
        if (lazy[i] == 0)
            return;

        if (i < t)
        {
            lazy[i * 2] ^= lazy[i];
            lazy[i * 2 + 1] ^= lazy[i];
        }

        tree[i] ^= lazy[i] * ((r - l + 1) % 2);
        lazy[i] = 0;
    }

    void Update(int s, int e, int k) { Update(s, e, k, 0, t - 1, 1); }
    void Update(int s, int e, int k, int l, int r, int i)
    {
        Propagate(l, r, i);

        if (r < s || e < l)
            return;
        if (s <= l && r <= e)
        {
            lazy[i] ^= k;
            Propagate(l, r, i);
            return;
        }

        int m = (l + r) / 2;
        Update(s, e, k, l, m, i * 2);
        Update(s, e, k, m + 1, r, i * 2 + 1);
        tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
    }

    int Query(int s, int e) { return Query(s, e, 0, t - 1, 1); }
    int Query(int s, int e, int l, int r, int i)
    {
        Propagate(l, r, i);

        if (r < s || e < l)
            return 0;
        if (s <= l && r <= e)
            return tree[i];

        int m = (l + r) / 2;
        int lSeg = Query(s, e, l, m, i * 2);
        int rSeg = Query(s, e, m + 1, r, i * 2 + 1);
        return lSeg ^ rSeg;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegTree seg(a);

    int m;
    cin >> m;

    for (int q = 1; q <= m; q++)
    {
        int query, a, b;
        cin >> query >> a >> b;

        if (query == 1)
        {
            int k;
            cin >> k;

            seg.Update(a, b, k);
        }
        else
        {
            int result = seg.Query(a, b);
            cout << result << '\n';
        }
    }
}