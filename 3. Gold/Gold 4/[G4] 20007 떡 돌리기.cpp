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

int MinDay(int x, int y, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<Edge> dist(n, { -1,INT_MAX });
    dist[y].w = 0;

    for (int i = 0; i < n; i++)
        dist[i].v = i;

    priority_queue<Edge> PQ;
    PQ.push({ y,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[u].w < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            int nw = w + edge.w;

            if (dist[v].w <= nw)
                continue;

            dist[v].w = nw;
            PQ.push({ v,nw });
        }
    }

    sort(dist.begin(), dist.end());

    int result = 0;
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (dist[i].w * 2 > x)
            return -1;

        if (sum + dist[i].w * 2 > x)
        {
            result++;
            sum = 0;
        }
        sum += dist[i].w * 2;
    }
    result++;
    return result;
}

int main()
{
    FastIO;

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    int result = MinDay(x, y, graph);
    cout << result << '\n';
}