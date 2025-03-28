#include <iostream>
#include <vector>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Node
{
    int value, cnt9;

    friend Node operator + (const Node& a, const Node& b)
    {
        return { a.value + b.value,a.cnt9 + b.cnt9 };
    }
};

struct SegTree
{
    int n, t;
    vector<Node> tree, lazy;

    SegTree(vector<int>& arr)
    {
        n = arr.size();
        t = bit_ceil((unsigned int)n);

        tree.resize(t, { 0,0 });
        lazy.resize(t, { 0,0 });
        for (int i = 0; i < n; i++)
            tree[t + i] = { arr[i],arr[i] == 9 };
        for (int i = t - 1; i >= 1; i--)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    void Propagate(int l, int r, int i)
    {
        if (lazy[i].value == 0)
            return;

        if (i < t)
        {
            lazy[i * 2] = lazy[i * 2] + lazy[i];
            lazy[i * 2 + 1] = lazy[i * 2 + 1] + lazy[i];
        }
        else
        {
            lazy
        }
        //tree[i] = lazy[];
        lazy[i] = { 0,0 };
    }
    void Update(int s, int e) { return Update(s, e, 0, t - 1, 1); }
    void Update(int s, int e, int l, int r, int i)
    {
        Propagate(l, r, i);

        if (r < s || e < l)
            return;
        if (s <= l && r <= e)
        {
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
            return { 0,0 };
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

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;

        arr[i] = a - '0';
    }

    SegTree seg(arr);
    for (int q = 1; q <= m; q++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        int result = seg.Query(a, b).value;
        cout << result << '\n';
    }
}