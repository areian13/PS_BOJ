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
        if (p[u] > p[v])
            swap(u, v);
        p[u] += p[v], p[v] = u;
    }

    int Size(int u) { return -p[Find(u)]; }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    UF uf(MAX);
    for (int i = 0; i < n; i++)
        uf.Union(a[i], b[i]);

    vector<int> cnt(MAX, 0);
    for (int i = 0; i < n; i++)
        cnt[uf.Find(a[i])]++;

    int result = 0;
    for (int i = 0; i < MAX; i++)
        result += min(uf.Size(i), cnt[i]);
    cout << result << '\n';
}