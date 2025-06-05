#include <iostream>
#include <vector>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Node
{
    long long v;
    int l, r;

    Node() : v(0), l(-1), r(-1) {}
    Node(long long v) : v(v), l(-1), r(-1) {}
};
struct PST
{
    int n;
    vector<Node> nodes;
    vector<int> roots;

    PST(vector<int>& a, int m)
    {
        n = a.size();
        nodes.reserve(n + m * bit_width((unsigned int)n - 1));
        roots.push_back(Build(0, n - 1, a));
    }
    int Build(int s, int e, vector<int>& a)
    {
        int u = nodes.size();
        nodes.push_back(Node());

        if (s == e)
        {
            nodes[u].v = a[s];
            return u;
        }

        int m = (s + e) / 2;
        nodes[u].l = Build(s, m, a);
        nodes[u].r = Build(m + 1, e, a);
        nodes[u].v = nodes[nodes[u].l].v + nodes[nodes[u].r].v;
        return u;
    }

    void Update(int i, int v)
    {
        int p = roots.back();
        roots.push_back(Update(p, 0, n - 1, i, v));
    }
    int Update(int p, int s, int e, int i, int v)
    {
        int u = nodes.size();
        nodes.push_back(nodes[p]);

        if (s == e)
        {
            nodes[u].v = v;
            return u;
        }

        int m = (s + e) / 2;
        if (i <= m)
            nodes[u].l = Update(nodes[p].l, s, m, i, v);
        else
            nodes[u].r = Update(nodes[p].r, m + 1, e, i, v);
        nodes[u].v = nodes[nodes[u].l].v + nodes[nodes[u].r].v;
        return u;
    }

    long long Query(int k, int i, int j)
    {
        return Query(roots[k], i, j, 0, n - 1);
    }
    long long Query(int u, int s, int e, int l, int r)
    {
        if (r < s || e < l)
            return 0;
        if (s <= l && r <= e)
            return nodes[u].v;

        int m = (l + r) / 2;
        long long lSeg = Query(nodes[u].l, s, e, l, m);
        long long rSeg = Query(nodes[u].r, s, e, m + 1, r);
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

    int m;
    cin >> m;

    PST pst(a, m);
    for (int qc = 1; qc <= m; qc++)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int i, v;
            cin >> i >> v;
            i--;

            pst.Update(i, v);
        }
        else
        {
            int k, i, j;
            cin >> k >> i >> j;
            i--, j--;

            long long result = pst.Query(k, i, j);
            cout << result << '\n';
        }
    }
}