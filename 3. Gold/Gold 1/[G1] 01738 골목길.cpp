#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w;
};

void DFS(int u, vector<bool>& isVisited, vector<vector<int>>& graph)
{
    isVisited[u] = true;

    for (int v : graph[u])
    {
        if (!isVisited[v])
            DFS(v, isVisited, graph);
    }
}

bool BF(int s, int t, vector<int>& dist, vector<int>& pre, vector<Edge> edges)
{
    int n = dist.size();

    dist[s] = 0;
    for (int i = 0; i < n; i++)
    {
        for (Edge& edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if (dist[u] != INT_MIN && dist[v] < dist[u] + w)
            {
                if (i == n - 1)
                    return false;

                dist[v] = dist[u] + w;
                pre[v] = u;
            }
        }
    }
    return (dist[t] != INT_MIN);
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Edge> tempEdges(m);
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        tempEdges[i] = { u,v,w };
        graph[v].push_back(u);
    }

    int s = 0, t = n - 1;
    vector<bool> isVisited(n, false);
    DFS(t, isVisited, graph);

    vector<Edge> edges;
    for (Edge& edge : tempEdges)
    {
        if (isVisited[edge.u] && isVisited[edge.v])
            edges.push_back(edge);
    }

    vector<int> dist(n, INT_MIN), pre(n, -1);
    bool canGo = BF(s, t, dist, pre, edges);
    if (!canGo)
        cout << -1 << '\n';
    else
    {
        vector<int> result;
        int x = t;
        while (x != -1)
        {
            result.push_back(x);
            x = pre[x];
        }
        reverse(result.begin(), result.end());

        for (int u : result)
            cout << u + 1 << ' ';
        cout << '\n';
    }
}