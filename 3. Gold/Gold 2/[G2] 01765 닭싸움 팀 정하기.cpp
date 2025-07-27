#include <iostream>
#include <vector>

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
        if (p[u] > p[v])
            swap(u, v);
        p[u] += p[v], p[v] = u;
    }
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    UnionFind uf(n);
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        char q;
        int u, v;
        cin >> q >> u >> v;
        u--, v--;

        if (q == 'F')
            uf.Union(u, v);
        else
        {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for(auto v : graph[i])
            uf.Union(graph[i][0], v);
    }

    int result = 0;
    for (int i = 0; i < n; i++)
        result += (uf.p[i] < 0);
    cout << result << '\n';
}