#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w;

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

void Highway(int n, vector<Edge>& edges, vector<array<int, 2>>& result)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    result.push_back({ 0,0 });
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (edge.w < 0)
            result[0][0] += -edge.w;

        if (u == v)
            continue;

        Union(u, v, p);

        if (edge.w > 0)
        {
            result[0][0] += edge.w;

            result[0][1]++;
            result.push_back({ edge.u + 1,edge.v + 1 });
        }
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Edge> edges;
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            int w;
            cin >> w;

            if (u >= v)
                continue;

            edges.push_back({ u,v,w });
        }
    }

    vector<array<int, 2>> result;
    Highway(n, edges, result);

    for (array<int, 2>& x : result)
        cout << x[0] << ' ' << x[1] << '\n';
}