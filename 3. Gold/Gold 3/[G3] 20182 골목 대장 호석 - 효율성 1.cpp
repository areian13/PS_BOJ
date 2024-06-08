#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v;
    long long c;
    int w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

int MinShame(int s, int t, int k, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    dist[s] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        long long c = PQ.top().c;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[u] < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            long long nc = c + edge.c;
            int nw = max(w, edge.w);

            if (dist[v] <= nw || nc > k)
                continue;

            dist[v] = nw;
            PQ.push({ v,nc,nw });
        }
    }
    if (dist[t] == INT_MAX)
        return -1;
    return dist[t];
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
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w,w });
        graph[v].push_back({ u,w,w });
    }

    int result = MinShame(a, b, c, graph);
    cout << result << '\n';
}