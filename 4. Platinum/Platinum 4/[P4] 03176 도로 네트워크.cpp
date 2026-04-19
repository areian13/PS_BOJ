#include <iostream>
#include <vector>
#include <bit>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Edge
{
    int v, w, W;
};
Edge save(const Edge& a, const Edge& b)
{
    int w = min(a.w, b.w);
    int W = max(a.W, b.W);
    return { a.v,w,W };
}

void MakeParent(int u, vector<int>& depth,
    vector<vector<Edge>>& parent, vector<vector<Edge>>& graph)
{
    for (auto& [v, w, W] : graph[u])
    {
        if (depth[v] != -1)
            continue;

        parent[v][0] = { u,w,W };
        depth[v] = depth[u] + 1;
        MakeParent(v, depth, parent, graph);
    }
}

Edge LCA(int u, int v, vector<int>& depth, vector<vector<Edge>>& parent)
{
    if (depth[u] > depth[v])
        swap(u, v);

    Edge result = { -1,INF,-INF };
    while (depth[u] < depth[v])
    {
        int i = 0;
        while (parent[v][i + 1].v != -1 && depth[u] < depth[parent[v][i + 1].v])
            i++;

        result = save(parent[v][i], result);
        v = parent[v][i].v;
    }

    while (u != v)
    {
        int i = 0;
        while (parent[u][i + 1].v != parent[v][i + 1].v)
            i++;

        result = save(result, parent[u][i]);
        result = save(result, parent[v][i]);
        u = parent[u][i].v;
        v = parent[v][i].v;
    }
    return result;
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

        graph[u].push_back({ v,w,w });
        graph[v].push_back({ u,w,w });
    }

    int t = bit_width((unsigned)n);
    vector<int> depth(n, -1);
    vector<vector<Edge>> parent(n, vector<Edge>(t, { -1,INF,-INF }));
    depth[0] = 0;
    MakeParent(0, depth, parent, graph);

    for (int j = 1; j < t; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (parent[i][j - 1].v == -1)
                continue;

            Edge& e = parent[i][j - 1];
            parent[i][j] = save(parent[e.v][j - 1], e);
        }
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        Edge result = LCA(u, v, depth, parent);
        cout << result.w << ' ' << result.W << '\n';
    }
}