#include <iostream>
#include <bit>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct SegTree
{
    int n, t;
    vector<long long> tree, lazy;

    SegTree(vector<long long>& arr)
    {
        n = arr.size();
        t = bit_ceil((unsigned int)n);

        tree.resize(t * 2, 0);
        lazy.resize(t * 2, 0);
        for (int i = 0; i < n; i++)
            tree[t + i] = arr[i];
        for (int i = t - 1; i >= 1; i--)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    void Propagate(int l, int r, int i)
    {
        if (lazy[i] == 0)
            return;

        if (i < t)
        {
            lazy[i * 2] += lazy[i];
            lazy[i * 2 + 1] += lazy[i];
        }

        tree[i] += lazy[i] * (r - l + 1);
        lazy[i] = 0;
    }
    void Update(int s, int e, long long v) { return Update(s, e, v, 0, t - 1, 1); }
    void Update(int s, int e, long long v, int l, int r, int i)
    {
        Propagate(l, r, i);

        if (r < s || e < l)
            return;
        if (s <= l && r <= e)
        {
            lazy[i] += v;
            Propagate(l, r, i);
            return;
        }

        int m = (l + r) / 2;
        Update(s, e, v, l, m, i * 2);
        Update(s, e, v, m + 1, r, i * 2 + 1);
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    long long Query(int s, int e) { return Query(s, e, 0, t - 1, 1); }
    long long Query(int s, int e, int l, int r, int i)
    {
        Propagate(l, r, i);

        if (r < s || e < l)
            return 0;
        if (s <= l && r <= e)
            return tree[i];

        int m = (l + r) / 2;
        long long lSeg = Query(s, e, l, m, i * 2);
        long long rSeg = Query(s, e, m + 1, r, i * 2 + 1);
        return lSeg + rSeg;
    }
};

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegTree seg(arr);
    for (int q = 1; q <= m + k; q++)
    {
        int query, a, b;
        cin >> query >> a >> b;
        a--, b--;

        if (a > b)
            swap(a, b);

        if (query == 1)
        {
            long long c;
            cin >> c;

            seg.Update(a, b, c);
        }
        else
        {
            long long result = seg.Query(a, b);
            cout << result << '\n';
        }
    }
}