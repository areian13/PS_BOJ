#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, c;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.c < b.c;
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

long long MinRoad(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    long long result = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v)
            continue;

        Union(u, v, p);
        result += edge.c;
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        vector<Edge> edges(n - 1);
        for (int u = 1; u <= n - 1; u++)
        {
            int v, c;
            cin >> v >> c;

            edges[u - 1] = { u,v,c };
        }

        long long result = 0;
        while (m--)
        {
            int u, v, c;
            cin >> u >> v >> c;

            edges.push_back({ u,v,c });
            result ^= MinRoad(n, edges);
        }
        cout << result << '\n';
    }
}