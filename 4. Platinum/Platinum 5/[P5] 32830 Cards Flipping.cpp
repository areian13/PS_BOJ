#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000'001

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
        p[u] += p[v], p[v] = u;
    }

    int Count(int u) { return -p[Find(u)]; }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> cards(n, vector<int>(2));
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < n; i++)
            cin >> cards[i][j];
    }

    UF uf(MAX);
    for (int i = 0; i < n; i++)
        uf.Union(cards[i][0], cards[i][1]);

    vector<int> cnt(MAX, 0);
    for (int i = 0; i < n; i++)
        cnt[uf.Find(cards[i][0])]++;

    int result = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (uf.Find(i) != i)
            continue;
        result += min(uf.Count(i), cnt[i]);
    }
    cout << result << '\n';
}