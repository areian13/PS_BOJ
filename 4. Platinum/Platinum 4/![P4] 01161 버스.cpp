#include <iostream>
#include <vector>
#include <algorithm>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Group
{
    int s, e, m;
};

struct Lazy
{
    int n, t;
    vector<int> tree, lazy;

    Lazy(int n) : n(n), t(bit_ceil(1u * n))
    {
        tree.resize(t * 2, 0);
        lazy.resize(t * 2, 0);
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
        else
            tree[i] += lazy[i];
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
            lazy[i] += k;
            Propagate(l, r, i);
            return;
        }

        int m = (l + r) / 2;
        Update(s, e, k, l, m, i * 2);
        Update(s, e, k, m + 1, r, i * 2 + 1);
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
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
        return lSeg + rSeg;
    }
};

int main()
{
    FastIO;

    int k, n, c;
    cin >> k >> n >> c;

    vector<Group> groups(k);
    for (auto& [s, e, m] : groups)
    {
        cin >> s >> e >> m;
        s--, e--;
    }
    sort(groups.begin(), groups.end(),
        [](auto& a, auto& b)
        {
            if (a.e != b.e) return a.e < b.e;
            return a.s < b.s;
        }
    );

    Lazy seg(n);
    long long result = 0;
    int last = 0;
    for (auto& [s, e, m] : groups)
    {
        int r = seg.Query(0, max(last - 1, s));
        int p = min(m, c - r);
        result += p;
        seg.Update(s, s, p);
        seg.Update(e, e, -p);
        last = e;
    }
    cout << result << '\n';
}