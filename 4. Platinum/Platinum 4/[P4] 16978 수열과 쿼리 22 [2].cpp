#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Node
{
    long long v;
    Node* l, * r;
    Node() : v(0), l(nullptr), r(nullptr) {}
};
struct PST
{
    int n;
    vector<Node*> roots;

    PST(vector<int>& a)
    {
        n = a.size();
        roots.push_back(new Node());
        Build(roots.back(), 0, n - 1, a);
    }
    void Build(Node* u, int s, int e, vector<int>& a)
    {
        if (s == e)
        {
            u->v = a[s];
            return;
        }

        int m = (s + e) / 2;
        u->l = new Node(); u->r = new Node();
        Build(u->l, s, m, a); Build(u->r, m + 1, e, a);
        u->v = (u->l->v) + (u->r->v);
    }

    void Update(int i, int v)
    {
        Node* p = roots.back();
        roots.push_back(new Node());
        Update(p, roots.back(), 0, n - 1, i, v);
    }
    void Update(Node* p, Node* u, int s, int e, int i, int v)
    {
        if (s == e)
        {
            u->v = v;
            return;
        }

        int m = (s + e) / 2;
        if (i <= m)
        {
            u->l = new Node();
            u->r = p->r;
            Update(p->l, u->l, s, m, i, v);
        }
        else
        {
            u->l = p->l;
            u->r = new Node();
            Update(p->r, u->r, m + 1, e, i, v);
        }
        u->v = (u->l->v) + (u->r->v);
    }

    long long Query(int k, int i, int j)
    {
        return Query(roots[k], i, j, 0, n - 1);
    }
    long long Query(Node* u, int s, int e, int l, int r)
    {
        if (r < s || e < l)
            return 0;
        if (s <= l && r <= e)
            return u->v;

        int m = (l + r) / 2;
        long long lSeg = Query(u->l, s, e, l, m);
        long long rSeg = Query(u->r, s, e, m + 1, r);
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

    PST pst(a);

    int m;
    cin >> m;

    for (int qn = 1; qn <= m; qn++)
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