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

    int n, q;
    cin >> n >> q;

    vector<pair<long long, long long>> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].first;
        s[i].second = s[i].first * s[i].first;
    }

    UnionFind uf(n);
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        u = uf.Find(u), v = uf.Find(v);

        if (u != v)
        {
            s[u].first += s[v].first, s[v].first = s[u].first;
            s[u].second += s[v].second, s[v].second = s[u].second;
            uf.Union(u, v);
        }

        long long result = (s[u].first * s[u].first - s[u].second) / 2;
        cout << result << '\n';
    }
}