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

        if (d > dist[u])
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            int nd = d + edge.d;

            if (nd >= dist[v])
                continue;

            dist[v] = nd;
            PQ.push({ v,nd });
        }
    }
    return dist[t];
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }

    int s, t;
    cin >> s >> t;
    s--, t--;

    int result = MinDist(s, t, graph);
    cout << result << '\n';
}