#include <iostream>
#include <bit>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF INT_MAX

struct Node
{
    int l, m, r;

    friend Node operator+(const Node& a, const Node& b)
    {
        int l = max({ a.l,a.m,a.r });
        int r = max({ b.l,b.m,b.r });

    }
    friend bool operator<(const Node& a, const Node& b)

};

Node SegTree(int s, int e, int l, int r, int i, vector<Node>& tree)
{
    if (r < s || e < l)
        return { -INF,-INF };
    if (s <= l && r <= e)
        return tree[i];
    int m = (l + r) / 2;
    Node lSeg = SegTree(s, e, l, m, i * 2, tree);
    Node rSeg = SegTree(s, e, m + 1, r, i * 2 + 1, tree);
    return lSeg + rSeg;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int t = bit_ceil((unsigned int)n);
    vector<Node> tree(t * 2, { -INF,-INF,-INF });
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        tree[t + i].m = a;
    }

    for (int i = t - 1; i >= 1; i--)
        tree[i] = tree[i * 2] + tree[i * 2 + 1];

    for (int i = 0; i < t * 2; i++)
    {
        cout << i << ' ' << tree[i].l << ' ' << tree[i].r << '\n';
    }

    Node a = SegTree(2, 3, 0, t - 1, 1, tree);
    Node b = SegTree(4, 5, 0, t - 1, 1, tree);
    Node result = a + b;
    cout << "            " << a.l << ' ' << a.r << '\n';
    cout << "            " << b.l << ' ' << b.r << '\n';
    cout << "            " << result.l << ' ' << result.r << '\n';

    int m;
    cin >> m;

    for (int q = 1; q <= m; q++)
    {
        int i, j;
        cin >> i >> j;
        i--, j--;

        Node result = SegTree(i, j, 0, t - 1, 1, tree);
        cout << "    " << result.l << ' ' << result.r << '\n';
        //cout << "    " << max({ result.l, result.r }) << '\n';
    }
}