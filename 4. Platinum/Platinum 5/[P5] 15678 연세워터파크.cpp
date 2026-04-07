#include <iostream>
#include <vector>
#include <bit>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct SegTree
{
    int n, t;
    vector<long long> tree;

    SegTree(vector<int>& a)
    {
        n = a.size();
        t = bit_ceil(a.size());
        tree.resize(t * 2, -INF);

        for (int i = 0; i < n; i++)
            tree[t + i] = a[i];
        for (int i = t - 1; i >= 1; i--)
            tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    }

    long long Query(int s, int e) { return Query(s, e, 0, t - 1, 1); }
    long long Query(int s, int e, int l, int r, int i)
    {
        if (r < s || e < l) return -INF;
        if (s <= l && r <= e) return tree[i];

        int m = (l + r) / 2;
        long long lSeg = Query(s, e, l, m, i * 2);
        long long rSeg = Query(s, e, m + 1, r, i * 2 + 1);
        return max(lSeg, rSeg);
    }

    void Update(int i, long long v)
    {
        i += t;
        tree[i] = v;
        while (i > 1)
        {
            i /= 2;
            tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
        }
    }
};

int main()
{
    FastIO;

    int n, d;
    cin >> n >> d;

    vector<int> k(n);
    for (int i = 0; i < n; i++)
        cin >> k[i];

    SegTree st(k);
    long long result = -INF;
    for (int i = 0; i < n; i++)
    {
        long long v = max(st.Query(i - d, i - 1), 0LL) + k[i];
        st.Update(i, v);

        result = max(result, v);
    }
    cout << result << '\n';
}