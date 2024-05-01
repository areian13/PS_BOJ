#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w;

    Edge() {}

    Edge(pair<int, int>& a, pair<int, int>& b)
    {
        u = a.second;
        v = b.second;
        w = abs(b.first - a.first);
    }

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

int MinPlanetTunnel(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    int result = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v)
            continue;

        Union(u, v, p);
        result += edge.w;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<pair<int, int>> xi(n);
    vector<pair<int, int>> yi(n);
    vector<pair<int, int>> zi(n);

    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        xi[i] = { x,i };
        yi[i] = { y,i };
        zi[i] = { z,i };
    }
    sort(xi.begin(), xi.end());
    sort(yi.begin(), yi.end());
    sort(zi.begin(), zi.end());

    vector<Edge> edges((n - 1) * 3);
    for (int i = 0; i < n - 1; i++)
    {
        edges[i * 3 + 0] = Edge(xi[i], xi[i + 1]);
        edges[i * 3 + 1] = Edge(yi[i], yi[i + 1]);
        edges[i * 3 + 2] = Edge(zi[i], zi[i + 1]);
    }

    int result = MinPlanetTunnel(n, edges);
    cout << result << '\n';
}