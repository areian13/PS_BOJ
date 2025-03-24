#include <iostream>
#include <bit>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 200'000
#define MOD 1'000'000'007

struct Node
{
    long long value;
    int cnt;

    friend Node operator+(const Node& a, const Node& b)
    {
        return { a.value + b.value,a.cnt + b.cnt };
    }
};

Node SegTree(int s, int e, int l, int r, int i, vector<Node>& tree)
{
    if (r < s || e < l)
        return { 0,0 };
    if (s <= l && r <= e)
        return tree[i];
    int m = (l + r) / 2;
    Node lSeg = SegTree(s, e, l, m, i * 2, tree);
    Node rSeg = SegTree(s, e, m + 1, r, i * 2 + 1, tree);
    return lSeg + rSeg;
}
void Update(int i, const Node& v, vector<Node>& tree)
{
    int t = tree.size() / 2;

    i += t;
    tree[i] = v;

    while (i > 1)
    {
        i /= 2;
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

int main()
{
    FastIO;

    constexpr int t = bit_ceil((unsigned int)MAX);
    vector<Node> tree(t * 2, { 0,0 });

    int n;
    cin >> n;

    long long result = 1;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;

        Update(x, tree[t + x] + Node{x, 1}, tree);

        if (i == 0)
            continue;

        Node lSeg = SegTree(0, x - 1, 0, t - 1, 1, tree);
        Node rSeg = SegTree(x + 1, MAX - 1, 0, t - 1, 1, tree);

        int lSum = (x * lSeg.cnt - lSeg.value) % MOD;
        int rSum = (rSeg.value - x * rSeg.cnt) % MOD;
        result *= (lSum + rSum) % MOD;
        result %= MOD;
    }
    cout << result << '\n';
}