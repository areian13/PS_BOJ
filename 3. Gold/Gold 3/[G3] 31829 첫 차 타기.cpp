#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v;
    long long w;
    bool isBus;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

long long MinTime(int k, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<long long> dist(n, LLONG_MAX);
    dist[0] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ 0,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        long long w = PQ.top().w;
        PQ.pop();

        if (dist[u] < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            bool isBus = edge.isBus;
            long long nw = w + edge.w + (isBus && w < k ? k - w : 0);

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }
    return dist[n - 1];
}

int main()
{
    FastIO;

    int n, k, x, y;
    cin >> n >> k >> x >> y;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < x + y; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w,i >= x });
        graph[v].push_back({ u,w,i >= x });
    }

    long long result = MinTime(k, graph);
    cout << result << '\n';
}