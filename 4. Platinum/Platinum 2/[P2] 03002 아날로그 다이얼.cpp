#include <iostream>
#include <vector>
#include <bit>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Node
{
    array<int, 10> cnt = { 0, };

    friend Node operator + (const Node& a, const Node& b)
    {
        array<int, 10> cnt;
        for (int i = 0; i < 10; i++)
            cnt[i] = a.cnt[i] + b.cnt[i];
        return { cnt };
    }
    friend Node operator >> (const Node& a, int n)
    {
        array<int, 10> cnt;
        for (int i = 0; i < 10; i++)
            cnt[(i + n) % 10] = a.cnt[i];
        return { cnt };
    }
};

struct SegTree
{
    int n, t;
    vector<Node> tree;
    vector<int> lazy;

    SegTree(vector<int>& a)
    {
        n = a.size();
        t = bit_ceil((unsigned int)n);

        tree.resize(t * 2, { false,0, });
        lazy.resize(t * 2, 0);
        for (int i = 0; i < n; i++)
            tree[t + i].cnt[a[i]]++;
        for (int i = t - 1; i >= 1; i--)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    void Propagate(int l, int r, int i)
    {
        if (lazy[i] == 0)
            return;

        if (l != r)
        {
            lazy[i * 2] += lazy[i];
            lazy[i * 2 + 1] += lazy[i];
        }

        tree[i] = tree[i] >> lazy[i];
        lazy[i] = 0;
    }
    void Update(int s, int e) { Update(s, e, 0, t - 1, 1); }
    void Update(int s, int e, int l, int r, int i)
    {
        Propagate(l, r, i);

        if (r < s || e < l)
            return;
        if (s <= l && r <= e)
        {
            lazy[i]++;
            Propagate(l, r, i);
            return;
        }

        int m = (l + r) / 2;
        Update(s, e, l, m, i * 2);
        Update(s, e, m + 1, r, i * 2 + 1);
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    Node Query(int s, int e) { return Query(s, e, 0, t - 1, 1); }
    Node Query(int s, int e, int l, int r, int i)
    {
        Propagate(l, r, i);

        if (r < s || e < l)
            return { 0, };
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

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        a[i] = c - '0';
    }

    SegTree seg(a);

    for (int q = 1; q <= m; q++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        Node result = seg.Query(a, b);
        int value = 0;
        for (int i = 0; i < 10; i++)
            value += result.cnt[i] * i;
        cout << value << '\n';

        seg.Update(a, b);
    }
}