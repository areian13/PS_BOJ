#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, c, w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

int MinCost(int t, int m, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<vector<int>> dist(n, vector<int>(m + 1, INT_MAX));
    dist[0][0] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ 0,0,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int c = PQ.top().c;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[u][c] < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            int nc = c + edge.c;
            int nw = w + edge.w;

            if (nc > m || nw > t || dist[v][nc] <= nw)
                continue;

            dist[v][nc] = nw;
            PQ.push({ v,nc,nw });
        }
    }

    int result = INT_MAX;
    for (int i = 0; i <= m; i++)
    {
        if (dist[n - 1][i] != INT_MAX)
            result = min(result, i);
    }

    if (result == INT_MAX)
        return -1;
    return result;
}

int main()
{
    FastIO;

    int n, t, m, l;
    cin >> n >> t >> m >> l;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < l; i++)
    {
        int u, v, d, w;
        cin >> u >> v >> d >> w;
        u--, v--;

        graph[u].push_back({ v,w,d });
        graph[v].push_back({ u,w,d });
    }

    int result = MinCost(t, m, graph);
    cout << result << '\n';
}