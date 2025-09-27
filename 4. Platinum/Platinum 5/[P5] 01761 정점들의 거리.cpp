#include <iostream>
#include <vector>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, w;
};

void MakeParent(int u, vector<int>& depth, vector<int>& dist,
    vector<vector<int>>& parent, vector<vector<Edge>>& graph)
{
    for (auto& [v, w] : graph[u])
    {
        if (depth[v] != -1)
            continue;

        depth[v] = depth[u] + 1;
        dist[v] = dist[u] + w;
        parent[v][0] = u;
        MakeParent(v, depth, dist, parent, graph);
    }
}

int GetDist(int u, int v, vector<int>& depth, vector<int>& dist,
    vector<vector<int>>& parent)
{
    int uDist = dist[u];
    int vDist = dist[v];

    if (depth[u] > depth[v])
        swap(u, v);
    while (depth[u] < depth[v])
    {
        int i = 0;
        while (parent[v][i + 1] != -1 && depth[u] < depth[parent[v][i + 1]])
            i++;
        v = parent[v][i];
    }

    while (u != v)
    {
        int i = 0;
        while (parent[u][i + 1] != parent[v][i + 1])
            i++;
        u = parent[u][i];
        v = parent[v][i];
    }

    return uDist + vDist - dist[u] * 2;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    int k = bit_width((unsigned)n);
    vector<vector<int>> parent(n, vector<int>(k, -1));
    vector<int> depth(n, -1), dist(n, -1);
    depth[0] = dist[0] = 0;
    MakeParent(0, depth, dist, parent, graph);

    for (int j = 1; j < k; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (parent[i][j - 1] != -1)
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    int m;
    cin >> m;

    for (int q = 1; q <= m; q++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        int result = GetDist(u, v, depth, dist, parent);
        cout << result << '\n';
    }
}