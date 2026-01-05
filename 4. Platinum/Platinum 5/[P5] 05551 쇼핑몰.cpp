#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Edge
{
    int u, v, w;
};

double MaxDist(vector<int>& shops, vector<Edge>& edges, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    auto comp = [](const Edge& a, const Edge& b) { return a.w > b.w; };
    vector<int> dist(n, INF);
    priority_queue<Edge, vector<Edge>, decltype(comp)> pq(comp);
    for (int shop : shops)
        dist[shop] = 0, pq.push({ -1,shop,0 });

    while (!pq.empty())
    {
        auto [p, u, d] = pq.top();
        pq.pop();

        if (dist[u] < d)
            continue;
        for (auto& [u, v, w] : graph[u])
        {
            int nw = d + w;
            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            pq.push({ -1,v,nw });
        }
    }

    double result = 0;
    for (auto& [u, v, w] : edges)
    {
        int dw = abs(dist[u] - dist[v]);
        result = max(result, max(dist[u], dist[v]) + (w - dw) / 2.);
    }
    return result;
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> graph(n);
    vector<Edge> edges(m);
    for (auto& [u, v, w] : edges)
    {
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ u,v,w });
        graph[v].push_back({ v,u,w });
    }

    vector<int> shops(k);
    for (int i = 0; i < k; i++)
    {
        cin >> shops[i];
        shops[i]--;
    }

    double result = MaxDist(shops, edges, graph);
    cout << (int)round(result) << '\n';
}