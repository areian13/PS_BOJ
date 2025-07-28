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

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        unordered_map<string, int> t;
        UnionFind uf(n * 2);
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            string u, v;
            cin >> u >> v;

            if (t.count(u) == 0)
                t[u] = k++;
            if (t.count(v) == 0)
                t[v] = k++;

            uf.Union(t[u], t[v]);
            cout << -uf.p[uf.Find(t[u])] << '\n';
        }
    }
}