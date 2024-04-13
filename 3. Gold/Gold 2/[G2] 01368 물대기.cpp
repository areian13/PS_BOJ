#include <iostream>
#include <vector>
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

int MinCost(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n + 1, -1);
    vector<bool> isLinkedSelf(n + 1, false);

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

    vector<Edge> edges;
    for (int u = 1; u <= n; u++)
    {
        int w;
        cin >> w;

        edges.push_back({ 0,u,w });
    }

    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            int w;
            cin >> w;

            if (u >= v)
                continue;

            edges.push_back({ u,v,w });
        }
    }

    int result = MinCost(n, edges);
    cout << result << '\n';
}