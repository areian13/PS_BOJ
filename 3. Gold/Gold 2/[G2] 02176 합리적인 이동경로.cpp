#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v;
    int w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

void GetDist(int s, vector<int>& dist, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    dist[s] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[u] < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            int nw = w + edge.w;

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }
}

int ReasonableRoute(int s, int t, vector<int>& dp, vector<int>& dist, vector<vector<Edge>>& graph)
{
    if (s == t)
        return dp[t] = 1;
    if (dp[s] != -1)
        return dp[s];

    int result = 0;
    for (Edge& edge : graph[s])
    {
        int v = edge.v;
        if (dist[v] < dist[s])
            result += ReasonableRoute(v, t, dp, dist, graph);
    }
    return dp[s] = result;
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

    vector<int> dist(n, INT_MAX);
    GetDist(1, dist, graph);

    vector<int> dp(n, -1);
    int result = ReasonableRoute(0, 1, dp, dist, graph);
    cout << result << '\n';
}