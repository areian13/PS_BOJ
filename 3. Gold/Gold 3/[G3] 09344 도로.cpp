#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

struct Edge
{
    int u;
    int v;
    int w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w < b.w;
    }
};

int Find(int u, vector<int>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}

void Union(int u, int v, vector<int>& p)
{
    p[v] = u;
}

bool IsUsefulRoad(int p, int q, int n, vector<Edge>& edges)
{
    if (p > q)
        swap(p, q);

    sort(edges.begin(), edges.end());

    vector<int> par(n, -1);
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, par);
        int v = Find(edge.v, par);

        if (u == v)
            continue;

        Union(u, v, par);

        if (min(p, q) == edge.u && max(p, q) == edge.v)
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m, p, q;
        cin >> n >> m >> p >> q;
        p--, q--;

        vector<Edge> edges(m);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;

            edges[i] = { min(u, v),max(u, v),w };
        }

        string result = (IsUsefulRoad(p, q, n, edges) ? "YES" : "NO");
        cout << result << '\n';
    }
}