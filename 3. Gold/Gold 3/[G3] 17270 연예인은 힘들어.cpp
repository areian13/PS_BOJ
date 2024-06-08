#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

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

void Dijkstra(int s, vector<int>& dist, vector<vector<Edge>>& graph)
{
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
            int nw = w + edge.w;

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }
}

int GoodPlace(int j, int s, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<int> jDist(n, INT_MAX);
    Dijkstra(j, jDist, graph);

    vector<int> sDist(n, INT_MAX);
    Dijkstra(s, sDist, graph);

    int minDist = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (i == j || i == s)
            continue;
        if (jDist[i] == INT_MAX || sDist[i] == INT_MAX)
            continue;
        minDist = min(minDist, jDist[i] + sDist[i]);
    }

    int result = -2;
    int minJDist = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (i == j || i == s)
            continue;
        if (jDist[i] == INT_MAX || sDist[i] == INT_MAX)
            continue;
        if (jDist[i] + sDist[i] > minDist)
            continue;
        if (jDist[i] > sDist[i])
            continue;

        if (minJDist > jDist[i])
        {
            minJDist = jDist[i];
            result = i;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int v, m;
    cin >> v >> m;

    vector<vector<Edge>> graph(v);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    int j, s;
    cin >> j >> s;
    j--, s--;

    int result = GoodPlace(j, s, graph);
    cout << result + 1 << '\n';
}