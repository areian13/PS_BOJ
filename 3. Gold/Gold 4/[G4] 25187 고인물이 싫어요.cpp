#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Find(int u, vector<int>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}
void Union(int u, int v, vector<int>& p)
{
    u = Find(u, p);
    v = Find(v, p);
    if (u == v)
        return;
    p[u] = v;
}

int main()
{
    FastIO;

    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int> clean(n);
    for (int i = 0; i < n; i++)
    {
        cin >> clean[i];
        clean[i] -= (clean[i] == 0);
    }

    vector<int> p(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (Find(u, p) == Find(v, p))
            continue;

        int sum = clean[Find(u, p)] + clean[Find(v, p)];
        Union(u, v, p);
        clean[Find(u, p)] = sum;
        clean[Find(v, p)] = sum;
    }

    for (int i = 0; i < q; i++)
    {
        int u;
        cin >> u;
        u--;

        cout << (clean[Find(u, p)] > 0) << '\n';
    }
}