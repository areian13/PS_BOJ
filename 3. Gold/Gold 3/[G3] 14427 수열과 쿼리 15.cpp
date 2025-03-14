#include <iostream>
#include <bit>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF INT_MAX

struct Node
{
    int v, i;

    friend bool operator<(const Node& a, const Node& b)
    {
        if (a.v != b.v)
            return a.v < b.v;
        return a.i < b.i;
    }
};

Node SegTree(int s, int e, int l, int r, int i, vector<Node>& a)
{
    if (r < s || e < l)
        return { INF,-1 };
    if (s <= l && r <= e)
        return a[i];

    int m = (l + r) / 2;
    Node lSeg = SegTree(s, e, l, m, i * 2, a);
    Node rSeg = SegTree(s, e, m + 1, r, i * 2 + 1, a);
    return min(lSeg, rSeg);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int k = bit_ceil((unsigned int)n);
    vector<Node> a(k * 2, { INF,-1 });
    for (int i = 0; i < n; i++)
    {
        cin >> a[k + i].v;
        a[k + i].i = i;
    }

    for (int i = k - 1; i >= 1; i--)
        a[i] = min(a[i * 2], a[i * 2 + 1]);

    int m;
    cin >> m;

    for (int t = 1; t <= m; t++)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int i, v;
            cin >> i >> v;
            
            i += k - 1;
            a[i].v = v;

            while (i > 1)
            {
                i /= 2;
                a[i] = min(a[i * 2], a[i * 2 + 1]);
            }
        }
        else
        {
            int s = 0, e = n - 1;
            Node result = SegTree(s, e, 0, k - 1, 1, a);
            cout << result.i + 1 << '\n';
        }
    }
}