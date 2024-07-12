#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v;
    long long w;
    int t;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

long long MinTime(int k, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<vector<long long>> dist(k + 1, vector<long long>(n, LLONG_MAX));
    dist[0][0] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ 0,0,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int t = PQ.top().t;
        long long w = PQ.top().w;
        PQ.pop();

        if (dist[t][u] < w)
            continue;

        for (int i = 0; i < 2; i++)
        {
            for (Edge& edge : graph[u])
            {
                int v = edge.v;
                int nt = t + i;
                long long nw = w + edge.w * !i;

                if (nt > k || dist[nt][v] <= nw)
                    continue;

                dist[nt][v] = nw;
                PQ.push({ v,nw,nt });
            }
        }
    }

    long long result = LLONG_MAX;
    for (int i = 0; i <= k; i++)
        result = min(result, dist[i][n - 1]);
    return result;
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    long long result = MinTime(k, graph);
    cout << result << '\n';
}