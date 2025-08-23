#include <iostream>
#include <vector>
#include <algorithm>

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
        p[v] = u;
    }
};

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> cards(m);
    for (int i = 0; i < m; i++)
        cin >> cards[i];
    sort(cards.begin(), cards.end());

    UnionFind uf(n + 1);
    for (int q = 0; q < k; q++)
    {
        int p;
        cin >> p;

        auto u = upper_bound(cards.begin(), cards.end(), p);
        while (uf.Find(*u) != *u)
            u++;
        uf.Union(0, *u);

        cout << *u << '\n';
    }
}