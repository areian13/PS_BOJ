#include <iostream>
#include <vector>
#include <cfloat>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v;
    double w;
};

void Dijkstra(int s, vector<double>& dist, vector<vector<Edge>>& graph)
{
    int n = graph.size();
    dist[s] = 0;

    auto comp = [](const Edge& a, const Edge& b) { return a.w > b.w; };
    priority_queue<Edge, vector<Edge>, decltype(comp)> PQ(comp);
    PQ.push({ s,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        double w = PQ.top().w;
        PQ.pop();

        if (dist[u] < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            double nw = (w == -DBL_MAX ? w : w + edge.w);

            if (dist[v] == -DBL_MAX)
                continue;
            if (dist[v] <= nw)
                continue;

            if(dist[v] < 0 && nw < 0)
                nw = -DBL_MAX;
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
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--, v--;

        double w = (a + b) / 2.0;
        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    vector<double> dist(n, DBL_MAX);
    Dijkstra(0, dist, graph);

    long long t;
    cin >> t;

    vector<int> result;
    for (int i = 1; i < n; i++)
    {
        if (dist[i] <= t)
            result.push_back(i);
    }

    int k = result.size();
    cout << k << '\n';
    for (int i = 0; i < k; i++)
        cout << result[i] + 1 << ' ';
    cout << '\n';
}