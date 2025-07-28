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
        p[min(u, v)] = max(u, v);
    }
};

int uize(int u, UnionFind& uf, vector<int>& x)
{
    return uf.Find(u) + (x[uf.Find(u)] != 0);
}

int main()
{
    FastIO;

    int n, q;
    cin >> n >> q;

    UnionFind uf(n + 1);
    vector<int> result(n + 1, 0);
    for (int i = 0; i < q; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        a--, b--;

        for (int j = uize(a, uf, result); j < n && j <= b; j = uize(j + 1, uf, result))
        {
            if (result[j] != 0)
                continue;

            result[j] = x;
            uf.Union(a, j);
        }
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << ' ';
    cout << '\n';
}