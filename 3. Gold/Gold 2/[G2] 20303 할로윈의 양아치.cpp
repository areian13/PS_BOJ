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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    UnionFind uf(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        uf.Union(u, v);
    }

    for (int i = 0; i < n; i++)
    {
        if (uf.Find(i) == i)
            continue;
        c[uf.Find(i)] += c[i];
    }

    vector<int> dp(k, 0);
    for (int i = 0; i < n; i++)
    {
        if (uf.Find(i) != i)
            continue;

        int s = -uf.p[i];
        for (int j = k - 1; j >= s; j--)
            dp[j] = max(dp[j], dp[j - s] + c[i]);
    }
    cout << dp[k - 1] << '\n';
}