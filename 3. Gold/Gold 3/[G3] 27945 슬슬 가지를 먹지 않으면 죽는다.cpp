#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, t;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.t < b.t;
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

int NoEggplantDay(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    int result = 1;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v || result != edge.t)
            break;

        Union(u, v, p);
        result++;
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        edges[i] = { u,v,w };
    }

    int result = NoEggplantDay(n, edges);
    cout << result << '\n';
}