#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, d, w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.d > b.d;
    }
};

int MinShame(int a, int b, int c, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    dist[a] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ a,0,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int d = PQ.top().d;
        int w = PQ.top().w;
        PQ.pop();

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            int nd = max(d, edge.d);
            int nw = w + edge.d;

            if (nw > c || nd >= dist[v])
                continue;

            dist[v] = nd;
            PQ.push({ v,nd,nw });
        }
    }

    return (dist[b] <= c ? dist[b] : -1);
}

int main()
{
    FastIO;

    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    a--, b--;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;

        graph[u].push_back({ v,d });
        graph[v].push_back({ u,d });
    }

    int result = MinShame(a, b, c, graph);
    cout << result << '\n';
}