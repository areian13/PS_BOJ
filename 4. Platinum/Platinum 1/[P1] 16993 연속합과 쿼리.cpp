#include <iostream>
#include <bit>
#include <vector>
#include <algorithm>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF INT_MAX

struct Node
{
    int l, r, m, s;

    friend Node operator+(const Node& a, const Node& b)
    {
        if (a.l == -INF)
            return b;
        if (b.l == -INF)
            return a;

        int l = max(a.l, a.s + b.l);
        int r = max(a.r + b.s, b.r);
        int m = max({ a.m,b.m,a.r + b.l });
        int s = a.s + b.s;
        return { l,r,m,s };
    }
};

struct SegTree
{
    int n, t;
    vector<Node> tree;

    SegTree(vector<int>& a)
    {
        n = a.size();
        t = bit_ceil((unsigned int)n);
        tree.resize(t * 2, { -INF,-INF,-INF,-INF });
        for (int i = 0; i < n; i++)
            tree[t + i] = { a[i],a[i],a[i],a[i] };
        for (int i = t - 1; i >= 1; i--)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    Node Query(int s, int e) { return Query(s, e, 0, t - 1, 1); }
    Node Query(int s, int e, int l, int r, int i)
    {
        if (r < s || e < l)
            return tree[0];
        if (s <= l && r <= e)
            return tree[i];

        int m = (l + r) / 2;
        Node lSeg = Query(s, e, l, m, i * 2);

        Node rSeg = Query(s, e, m + 1, r, i * 2 + 1);
        return lSeg + rSeg;
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
        int i, j;
        cin >> i >> j;
        i--, j--;

        Node result = seg.Query(i, j);
        cout << result.m << '\n';
    }
}