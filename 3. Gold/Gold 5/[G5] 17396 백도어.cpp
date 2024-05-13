#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v;
    long long d;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.d > b.d;
    }
};

long long MinBackDoorTime(vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<long long> dist(n, LLONG_MAX);
    dist[0] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ 0,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        long long d = PQ.top().d;
        PQ.pop();

        if (d > dist[u])
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            long long nd = d + edge.d;

            if (dist[v] <= nd)
                continue;

            dist[v] = nd;
            PQ.push({ v,nd });
        }
    }

    long long result = (dist[n - 1] != LLONG_MAX ? dist[n - 1] : -1);
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<bool> isVisible(n, false);
    for (int i = 0; i < n; i++)
    {
        bool a;
        cin >> a;

        isVisible[i] = a;
    }
    isVisible[n - 1] = false;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;

        if (isVisible[a] || isVisible[b])
            continue;

        graph[a].push_back({ b,t });
        graph[b].push_back({ a,t });
    }

    long long result = MinBackDoorTime(graph);
    cout << result << '\n';
}