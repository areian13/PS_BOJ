#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, d;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.d > b.d;
    }
};

int MinDist(int s, int t, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    dist[s] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int d = PQ.top().d;
        PQ.pop();

        if (dist[u] < d)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            int nd = d + edge.d;

            if (dist[v] <= nd)
                continue;

            dist[v] = nd;
            PQ.push({ v,nd });
        }
    }
    if (dist[t] == INT_MAX)
        return -1;
    return dist[t];
}

int main()
{
    FastIO;

    int n, v, e, a, b;
    cin >> n >> v >> e >> a >> b;;
    a--, b--;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        h[i]--;
    }

    vector<vector<Edge>> graph(v);
    for (int i = 0; i < e; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;

        graph[u].push_back({ v,d });
        graph[v].push_back({ u,d });
    }

    int result = 0;
    for (int i = 0; i < n; i++)
        result += (MinDist(h[i], a, graph) + MinDist(h[i], b, graph));
    cout << result << '\n';
}