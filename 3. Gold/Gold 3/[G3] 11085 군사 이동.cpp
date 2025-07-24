#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w;
};

struct UF
{
    vector<int> p;

    UF(int n) { p.resize(n, -1); }
    int Find(int u) { return p[u] < 0 ? u : p[u] = Find(p[u]); }
    void Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if (u == v)
            return;
        if (p[u] > p[v])
            swap(u, v);
        p[u] += p[v], p[v] = u;
    }
};

int MaxWeight(int s, int t, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    queue<int> Q;
    vector<int> dist(n, -1);
    Q.push(s);
    dist[s] = 1e9 + 1;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (auto& [u, v, w] : graph[u])
        {
            if (dist[v] != -1)
                continue;

            dist[v] = min(dist[u], w);
            Q.push(v);
        }
    }
    return dist[t];
}

int main()
{
    FastIO;

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges[i] = { u,v,w };
    }
    sort(edges.begin(), edges.end(),
        [](const Edge& a, const Edge& b)
        { return a.w > b.w; }
    );

    vector<vector<Edge>> graph(n);
    UF uf(n);
    for (int i = 0; i < m; i++)
    {
        auto [u, v, w] = edges[i];

        if (uf.Find(u) == uf.Find(v))
            continue;

        uf.Union(u, v);
        graph[u].push_back({ u,v,w });
        graph[v].push_back({ v,u,w });
    }

    int result = MaxWeight(s, t, graph);
    cout << result << '\n';
}