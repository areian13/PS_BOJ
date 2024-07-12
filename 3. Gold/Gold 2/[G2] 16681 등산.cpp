#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

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

void Dijkstra(int s, vector<long long>& dist, vector<int>& h, vector<vector<Edge>>& graph)
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

            if (h[u] >= h[v])
                continue;

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

    int n, m, d, e;
    cin >> n >> m >> d >> e;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    vector<long long> hDist(n, LLONG_MAX);
    Dijkstra(0, hDist, h, graph);

    vector<long long> uDist(n, LLONG_MAX);
    Dijkstra(n - 1, uDist, h, graph);

    long long result = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        if (hDist[i] == LLONG_MAX || uDist[i] == LLONG_MAX)
            continue;

        long long value = h[i] * e - (hDist[i] + uDist[i]) * d;
        result = max(result, value);
    }

    if (result == LLONG_MIN)
        cout << "Impossible" << '\n';
    else
        cout << result << '\n';
}