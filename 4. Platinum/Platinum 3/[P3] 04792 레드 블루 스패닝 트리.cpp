#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

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
        if (p[u] < p[v])
            swap(u, v);
        p[u] += p[v], p[v] = u;
    }
};
struct Edge
{
    int u, v, w;
};

int MST(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end(),
        [](const Edge& a, const Edge& b) { return a.w < b.w; }
    );

    UnionFind uf(n);
    int result = 0;
    for (auto& [u, v, w] : edges)
    {
        if (uf.Find(u) == uf.Find(v))
            continue;

        result += w;
        uf.Union(u, v);
    }
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        int n, m, k;
        cin >> n >> m >> k;

        if (n == 0 && m == 0 && k == 0)
            break;

        vector<Edge> edges(m);
        for (int i = 0; i < m; i++)
        {
            char c;
            int u, v;
            cin >> c >> u >> v;
            u--, v--;

            edges[i] = { u,v,c == 'B' };
        }

        int mst = MST(n, edges);

        for (int i = 0; i < m; i++)
            edges[i].w *= -1;

        int Mst = -MST(n, edges);

        cout << (mst <= k && k <= Mst) << '\n';
    }
}