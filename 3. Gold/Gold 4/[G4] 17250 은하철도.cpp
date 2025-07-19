#include <iostream>
#include <vector>
#include <unordered_map>

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

    int n, m;
    cin >> n >> m;

    vector<int> stars(n);
    for (int& star : stars)
        cin >> star;

    vector<int> p(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        int star = stars[Find(u, p)] + stars[Find(v, p)];

        if (Find(u, p) == Find(v, p))
            star /= 2;

        Union(u, v, p);
        stars[Find(u, p)] = star;
        stars[Find(v, p)] = star;

        cout << star << '\n';
    }
}