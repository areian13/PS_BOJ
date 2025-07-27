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

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b(n);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        result += (a[i] < b[i]);
    }

    UnionFind uf(n);
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            u = uf.Find(u), v = uf.Find(v);

            if (u == v)
                continue;

            bool uk = (a[u] < b[u]);
            bool vk = (a[v] < b[v]);

            a[u] += a[v], a[v] = a[u];
            b[u] += b[v], b[v] = b[u];

            if (a[u] >= b[u])
                result -= uf.Count(u) * uk + uf.Count(v) * vk;
            else
                result += uf.Count(u) * !uk + uf.Count(v) * !vk;

            uf.Union(u, v);
        }
        else
            cout << result << '\n';
    }
}