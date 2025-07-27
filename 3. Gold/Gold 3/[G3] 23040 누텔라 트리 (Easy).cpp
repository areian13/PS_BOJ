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

    int Count(int u) { return -p[Find(u)]; }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    string colors;
    cin >> colors;

    UnionFind uf(n);
    for (int u = 0; u < n; u++)
    {
        if (colors[u] == 'B')
            continue;

        for (int v : tree[u])
        {
            if (colors[v] == 'B')
                continue;

            uf.Union(u, v);
        }
    }

    long long result = 0;
    for (int u = 0; u < n; u++)
    {
        if (colors[u] != 'B')
            continue;

        for (int v : tree[u])
        {
            if (colors[v] == 'B')
                continue;

            result += uf.Count(v);
        }
    }
    cout << result << '\n';
}