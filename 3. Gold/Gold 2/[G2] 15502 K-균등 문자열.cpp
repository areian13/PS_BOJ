#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000'000'007

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
    for (int i = 0; i < m; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;

        for (int j = 0; j < k; j++)
        {
            for (int x = l + j + k; x <= r; x += k)
                uf.Union(l + j, x);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += (uf.Find(i) == i);

    int result = 1;
    for (int i = 0; i < cnt; i++)
        result = result * 2 % MOD;
    cout << result << '\n';
}