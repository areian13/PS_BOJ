#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, w, d;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.d > b.d;
    }
};

int MinOilCost(int u, vector<int>& cost, vector<int>& dist, vector<vector<Edge>>& graph)
{
    if (dist[u] != INT_MAX)
        return dist[u];

    int n = cost.size();

    priority_queue<Edge> PQ;
    PQ.push({ 0,cost[0],0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().w;
        int d = PQ.top().d;
        PQ.pop();

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            int nw = min(w, edge.w);
            int nd = d + (edge.d * nw);

            if (dist[v] <= nd)
                continue;

            dist[v] = nd;
            PQ.push({ v,nw,nd });
        }
    }
    return dist[n - 1];
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;

        graph[u].push_back({ v,cost[u],d });
        graph[v].push_back({ u,cost[v],d });
    }

    vector<int> dist(n, INT_MAX);
    int result = MinOilCost(0, cost, dist, graph);
    cout << result << '\n';
}