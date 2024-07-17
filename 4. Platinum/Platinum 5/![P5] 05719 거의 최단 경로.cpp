#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, w;
    bool canGo;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

int Dijkstra(int s, int t, vector<int>& dist, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    dist[s] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[u] < w)
            continue;

        for (Edge& edge : graph[u])
        {
            if (!edge.canGo)
                continue;

            int v = edge.v;
            int nw = w + edge.w;

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }

    if (dist[t] == INT_MAX)
        return -1;
    return dist[t];
}

bool EraseEdge(int u, int t, vector<int>& type, vector<int>& dist, vector<vector<Edge>>& graph)
{
    if (u == t)
        return type[u] = false;

    int w = dist[u];

    for (Edge& edge : graph[u])
    {
        int v = edge.v;
        int nw = w + edge.w;

        if (dist[v] < nw)
            continue;

        if (dist[v] == nw && type[v] != -1)
        {
            edge.canGo = type[v];
            type[u] &= type[v];
            continue;
        }
        if (!EraseEdge(v, t, type, dist, graph))
        {
            edge.canGo = false;
            type[u] = type[v] = false;
        }
    }
    return type[u];
}

int AlmostMinDist(int s, int t, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    int minDist = Dijkstra(s, t, dist, graph);
    if (minDist == -1)
        return -1;

    vector<int> type(n, -1);
    EraseEdge(s, t, type, dist, graph);

    fill(dist.begin(), dist.end(), INT_MAX);
    return Dijkstra(s, t, dist, graph);
}

int main()
{
    FastIO;

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        int s, t;
        cin >> s >> t;

        vector<vector<Edge>> graph(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            graph[u].push_back({ v,w,true });
        }

        int result = AlmostMinDist(s, t, graph);
        cout << result << '\n';
    }
}