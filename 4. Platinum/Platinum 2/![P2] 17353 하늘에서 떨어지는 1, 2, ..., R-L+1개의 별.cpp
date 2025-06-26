#include <iostream>
#include <vector>
#include <bit>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long Sum(long long n)
{
    return n * (n + 1) / 2;
}

struct Op
{
    int s, l, r;

    long long Sum()
    {
        return ::Sum(r - s + 1) - ::Sum(l - s);
    }
};

struct SegTree
{
    int n, t;
    vector<long long> tree, lazy;

    SegTree(vector<int>& a)
    {
        n = a.size();
        t = bit_ceil(a.size());

        tree.resize(t * 2);
        lazy.resize(t * 2, 0);
        for (int i = 0; i < n; i++)
            tree[t + i] = a[i];
        for (int i = t - 1; i >= 1; i--)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    void Propagate(int s, int l, int r, int i)
    {
        if (lazy[i] == 0)
            return;

        if (l != r)
        {
            long long lv = Op(s, l, (l + r + 1) / 2).Sum();
            lazy[i * 2] += lv;
            lazy[i * 2 + 1] += lazy[i] - lv;
        }

        tree[i] += lazy[i];
        lazy[i] = 0;
    }
    void Update(int s, int e) { Update(s, e, 0, t - 1, 1); }
    void Update(int s, int e, int l, int r, int i)
    {
        Propagate(s, l, r, i);

        if (r < s || e < l)
            return;
        if (s <= l && r <= e)
        {
            lazy[i] += Op(s, l, r).Sum();
            Propagate(s, l, r, i);
            return;
        }

        int m = (l + r) / 2;
        Update(s, e, l, m, i * 2);
        Update(s, e, m + 1, r, i * 2 + 1);
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    long long Query(int s, int e) { return Query(s, e, 0, t - 1, 1); }
    long long Query(int s, int e, int l, int r, int i)
    {
        Propagate(s, l, r, i);

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

    /*while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--,b--,c--;

        cout << Op(a, b, c).Sum() << '\n';
    }*/

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegTree seg(a);

    int QC;
    cin >> QC;

    for (int qc = 1; qc <= QC; qc++)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;

            seg.Update(l, r);
        }
        else
        {
            int x;
            cin >> x;
            x--;

            long long result = seg.Query(x, x);
            cout << result << '\n';
        }
    }
}