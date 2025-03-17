#include <iostream>
#include <bit>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int SegTree(int v, int s, int e, int i, vector<int>& tree)
{
    if (s == e)
        return s;

    int m = (s + e) / 2;
    if (tree[i * 2] >= v)
        return SegTree(v, s, m, i * 2, tree);
    else
        return SegTree(v - tree[i * 2], m + 1, e, i * 2 + 1, tree);
}

void Update(int idx, int value, vector<int>& tree)
{
    int t = tree.size() / 2;

    idx += t;
    tree[idx] = value;

    while (idx > 1)
    {
        idx /= 2;
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    int t = bit_ceil((unsigned int)n);
    vector<int> tree(t * 2, 0);
    for (int i = 0; i < n; i++)
        tree[t + i] = 1;
    for (int i = t - 1; i >= 1; i--)
        tree[i] = tree[i * 2] + tree[i * 2 + 1];

    vector<int> result(n);
    int u = 0;
    for (int i = 0; i < n; i++)
    {
        u = (u + k - 1) % (n - i);
        int v = SegTree(u + 1, 0, t - 1, 1, tree);
        Update(v, 0, tree);

        result[i] = v;
    }

    cout << '<';
    for (int i = 0; i < n; i++)
    {
        cout << result[i] + 1;
        if (i != n - 1)
            cout << ", ";
    }
    cout << ">\n";
}