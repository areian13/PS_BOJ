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

int main()
{
    FastIO;

    int n, QC;
    cin >> n >> QC;

    vector<int> m(n);
    for (int i = 0; i < n; i++)
        cin >> m[i];

    UnionFind uf(n + 1);
    vector<int> d(n, 0);
    for (int qc = 1; qc <= QC; qc++)
    {
        int q, i;
        cin >> q >> i;
        i--;

        if (q == 1)
        {
            int x;
            cin >> x;

            int s = i;
            for (int j = uf.Find(i); j < n && x > 0; j = uf.Find(j) + 1)
            {
                int k = min(x, m[j] - d[j]);
                x -= k, d[j] += k;

                if (d[j] == m[j])
                    uf.Union(s, j);
                else
                    s = j;
            }
        }
        else
            cout << d[i] << '\n';
    }
}