#include <iostream>
#include <vector>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX_XY 1e5

struct Node
{
    int v;
    Node* l, * r;
    Node() : v(0), l(nullptr), r(nullptr) {}
};
struct PST
{
    int n, r;
    unordered_map<int, Node*> roots;

    PST()
    {
        n = MAX_XY + 1;
        r = -1;
        roots[r] = new Node();
        Build(roots[r], 0, n - 1);
    }
    void Build(Node* u, int s, int e)
    {
        if (s == e)
            return;

        int m = (s + e) / 2;
        u->l = new Node(), u->r = new Node();
        Build(u->l, s, m), Build(u->r, m + 1, e);
    }

    void Update(int x, int y)
    {
        Node* p = roots[r];
        if (roots[x] == nullptr)
            roots[x] = new Node();
        r = x;
        Update(p, roots[x], 0, n - 1, y);
    }
    void Update(Node* p, Node* u, int s, int e, int y)
    {
        if (s == e)
        {
            u->v++;
            return;
        }

        int m = (s + e) / 2;
        if (y <= m)
        {
            u->l = new Node();
            u->r = p->r;
            Update(p->l, u->l, s, m, y);
        }
        else
        {
            u->l = p->l;
            u->r = new Node();
            Update(p->r, u->r, m + 1, e, y);
        }
        u->v = (u->l->v) + (u->r->v);
    }

    int Query(int l, int r, int b, int t)
    {
        int rt = Query(roots[])
    }
    int Query(Node* u, int s, int e, int l, int r)
    {
        if (r < s || e < l)
            return 0;
        if (s <= l && r <= e)
            return u->v;

        int m = (l + r) / 2;
        int lSeg = Query(u->l, s, e, l, m);
        int rSeg = Query(u->r, s, e, m + 1, r);
        return lSeg + rSeg;
    }
};

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, m;
        cin >> n >> m;


        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;


        }

        for (int q = 1; q <= m; q++)
        {
            int l, r, b, t;
            cin >> l >> r >> b >> t;


        }
    }
}