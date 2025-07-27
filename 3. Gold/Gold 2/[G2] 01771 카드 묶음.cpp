#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Node
{
    int m, M, i;
};
struct UnionFind
{
    vector<int> p;
    UnionFind(int n) { p.resize(n, -1); }
    int Find(int u) { return p[u] < 0 ? u : p[u] = Find(p[u]); }
    void Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if (u == v)
            return;
        if (p[u] > p[v])
            swap(u, v);
        p[u] += p[v], p[v] = u;
    }
};

bool CanUnion(Node& a, Node& b)
{
    return a.m == b.M + 1 || a.M == b.m - 1;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Node> cards(n);
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        v--;
        cards[i] = { v,v,i };
    }

    UnionFind uf(n);
    vector<Node> stk;
    for (int i = 0; i < n; i++)
    {
        stk.push_back(cards[i]);

        while (stk.size() >= 2)
        {
            Node b = stk.back();
            stk.pop_back();
            Node a = stk.back();
            stk.pop_back();

            if (!CanUnion(a, b))
            {
                stk.push_back(a);
                stk.push_back(b);
                break;
            }

            cout << a.i + 1 << '\n';
            uf.Union(a.i, b.i);

            Node c;
            c.m = min(a.m, b.m);
            c.M = max(a.M, b.M);
            c.i = b.i;
            stk.push_back(c);
        }
    }
}