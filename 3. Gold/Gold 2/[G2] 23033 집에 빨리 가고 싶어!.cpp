#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, w, t;
};

int NT(int w, int t)
{
    return (w / t + (w % t != 0)) * t;
}

int MinTime(int s, int t, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    dist[s] = 0;

    auto comp = [](const Edge& a, const Edge& b) { return a.w > b.w; };
    priority_queue<Edge, vector<Edge>, decltype(comp)> PQ(comp);
    PQ.push({ s,dist[s] });

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
            int nw = NT(w, edge.t) + edge.w;

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }
    return dist[t];
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w, t;
        cin >> u >> v >> w >> t;
        u--, v--;

        graph[u].push_back({ v,w,t });
    }

    int result = MinTime(0, n - 1, graph);
    cout << result << '\n';
}