#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

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

long long f(long long n)
{
    return (n * n + n) / 2;
}
long long F(long long n)
{
    return (n * n * n + 3 * n * n + 2 * n) / 6;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    UnionFind uf(n);
    long long pair = 0, bridges = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u;
        cin >> u;
        u--;

        int p = uf.Find(u);
        int q = uf.Find(u + 1);

        pair -= f(-uf.p[p] - 1) + f(-uf.p[q] - 1);
        bridges -= F(-uf.p[p] - 1) + F(-uf.p[q] - 1);
        uf.Union(u, u + 1);

        int k = -uf.p[uf.Find(u)] - 1;
        pair += f(k);
        bridges += F(k);

        cout << pair << ' ' << bridges << '\n';
    }
}