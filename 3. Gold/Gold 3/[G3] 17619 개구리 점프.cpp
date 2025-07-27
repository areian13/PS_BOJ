#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Log
{
    int x1, x2, y, i;
};
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

    int n, q;
    cin >> n >> q;

    vector<Log> logs(n);
    for (int i = 0; i < n; i++)
    {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;

        logs[i] = { x1,x2,y,i };
    }
    sort(logs.begin(), logs.end(),
        [](const Log& a, const Log& b)
        {
            if (a.x1 != b.x1)
                return a.x1 < b.x1;
            return a.x2 < b.x2;
        }
    );

    UnionFind uf(n);
    int x = 0;
    for (int i = 0, j = 1; i < n; i++)
    {
        if (logs[i].x2 < x)
            continue;

        j = max(j, i + 1);
        x = max(x, logs[i].x2);
        while (j < n && logs[j].x1 <= x)
        {
            uf.Union(logs[i].i, logs[j].i);
            x = max(x, logs[j].x2);
            j++;
        }
    }

    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        bool result = (uf.Find(u) == uf.Find(v));
        cout << result << '\n';
    }
}