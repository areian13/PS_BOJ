#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v;
    long long w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

void Dijkstra(int s, vector<long long>& dist, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    dist[s] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        long long w = PQ.top().w;
        PQ.pop();

        if (dist[u] < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            long long nw = w + edge.w;

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }
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
        graph[v].push_back({ u,w });
    }

    int x, z;
    cin >> x >> z;
    x--, z--;

    vector<long long> xDist(n, LLONG_MAX);
    Dijkstra(x, xDist, graph);

    vector<long long> zDist(n, LLONG_MAX);
    Dijkstra(z, zDist, graph);

    int p;
    cin >> p;

    long long result = LLONG_MAX;
    for (int i = 0; i < p; i++)
    {
        int y;
        cin >> y;
        y--;

        if (xDist[y] == LLONG_MAX || zDist[y] == LLONG_MAX)
            continue;

        result = min(result, xDist[y] + zDist[y]);
    }

    result = (result == LLONG_MAX ? -1 : result);
    cout << result << '\n';
}