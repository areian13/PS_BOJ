#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF LLONG_MAX

struct Edge
{
    int v;
    long long w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    };
};

void Dijkstra(int s, vector<long long>& dist, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    priority_queue<Edge> PQ;
    PQ.push({ s,0 });
    dist[s] = 0;

    while (!PQ.empty())
    {
        auto [u, d] = PQ.top();
        PQ.pop();

        if (d > dist[u])
            continue;

        for (auto& [v, w] : graph[u])
        {
            long long nd = d + w;

            if (dist[v] <= nd)
                continue;

            dist[v] = nd;
            PQ.push({ v,nd });
        }
    }
}

long long TSP(int u, int t, int isVisited, vector<vector<long long>>& dists,
    vector<vector<long long>>& dp)
{
    int n = dists.size();
    long long& result = dp[u][isVisited];

    if (result != -1)
        return result;
    if (isVisited == (1 << (n - 1)) - 1)
        return dists[u][t];

    result = INF;
    for (int v = 1; v < n - 1; v++)
    {
        if (dists[u][v] == INF || isVisited & (1 << v))
            continue;

        long long d = TSP(v, t, isVisited | (1 << v), dists, dp);
        if (d == INF)
            continue;
        result = min(result, d + dists[u][v]);
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    int x, z, p;
    cin >> x >> z >> p;
    x--, z--, p += 2;

    vector<int> y(p);
    y[0] = x, y[p - 1] = z;
    vector<vector<long long>> dists(p, vector<long long>(p, INF));
    for (int i = 1; i < p - 1; i++)
    {
        cin >> y[i];
        y[i]--;
    }
    for (int i = 0; i < p; i++)
    {
        vector<long long> dist(n, INF);
        Dijkstra(y[i], dist, graph);

        for (int j = 0; j < p; j++)
            dists[i][j] = dist[y[j]];
    }

    vector<vector<long long>> dp(p, vector<long long>(1 << p, -1));
    long long result = TSP(0, p - 1, 1, dists, dp);
    if (result == INF)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}