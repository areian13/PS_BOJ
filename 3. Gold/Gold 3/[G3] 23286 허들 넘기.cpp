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

void MinMaxHurdle(int s, vector<int>& dist, vector<vector<Edge>>& graph)
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
            int v = edge.v;
            int nw = max(w, edge.w);

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

    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, h;
        cin >> u >> v >> h;
        u--, v--;

        graph[u].push_back({ v,h });
    }

    vector<vector<int>> dists(n, vector<int>(n, INT_MAX));
    vector<bool> isCalculated(n, false);
    while (t--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (!isCalculated[u])
        {
            MinMaxHurdle(u, dists[u], graph);
            isCalculated[u] = true;
        }
        int result = (dists[u][v] == INT_MAX ? -1 : dists[u][v]);
        cout << result << '\n';
    }
}