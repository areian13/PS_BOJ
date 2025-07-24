#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct UF
{
    vector<int> p;

    UF(int n) { p.resize(n, -1); }
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

    UF uf(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;

        uf.p[i] = -k;
    }

    for (int i = 0; i < m; i++)
    {
        int q, u, v;
        cin >> q >> u >> v;

        if (q == 1)
            uf.Union(u, v);
        else
        {
            u = uf.Find(u), v = uf.Find(v);

            if (u == v)
                continue;
            if (uf.p[u] == uf.p[v])
                uf.p[u] = uf.p[v] = 0;
            else
            {
                if (-uf.p[u] < -uf.p[v])
                    swap(u, v);

                uf.p[u] -= uf.p[v], uf.p[v] = u;
            }
        }
    }

    vector<int> result;
    for (int i = 1; i <= n; i++)
    {
        if (uf.p[i] < 0)
            result.push_back(-uf.p[i]);
    }
    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (auto i : result)
        cout << i << ' ';
}