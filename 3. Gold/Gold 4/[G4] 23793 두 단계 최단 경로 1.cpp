#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

int Dijkstra(int x, int y, int z, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    dist[x] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ x,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[u] < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            int nw = w + edge.w;

            if (v == y || dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }

    if (dist[z] == INT_MAX)
        return -1;
    return dist[z];
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
    }

    int x, y, z;
    cin >> x >> y >> z;
    x--, y--, z--;

    vector<int> result(3);
    result[0] = Dijkstra(x, n, y, graph);
    result[1] = Dijkstra(y, n, z, graph);
    result[2] = Dijkstra(x, y, z, graph);

    if (result[0] == -1 || result[1] == -1)
        result[1] = -1;
    else
        result[1] += result[0];

    cout << result[1] << ' ' << result[2] << '\n';
}