#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, f;
    long long w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

long long MinTime(vector<vector<vector<Edge>>>& graph)
{
    int k = graph.size();
    int n = graph[0].size();

    vector<vector<long long>> dist(k, vector<long long>(n, LLONG_MAX));
    dist[0][0] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ 0,0,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int f = PQ.top().f;
        long long w = PQ.top().w;
        PQ.pop();

        if (dist[f][u] < w)
            continue;

        for (Edge& edge : graph[f][u])
        {
            int v = edge.v;
            int nf = edge.f;
            long long nw = w + edge.w;

            if (dist[nf][v] <= nw)
                continue;

            dist[nf][v] = nw;
            PQ.push({ v,nf,nw });
        }
    }

    if (dist[k - 1][n - 1] == LLONG_MAX)
        return -1;
    return dist[k - 1][n - 1];
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<vector<Edge>>> graph(2, vector<vector<Edge>>(n));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        for (int j = 0; j < 2; j++)
        {
            graph[j][u].push_back({ v,j,w });
            graph[j][v].push_back({ u,j,w });
        }
    }

    for (int i = 0; i < n; i++)
    {
        long long w;
        cin >> w;

        if (w == -1)
            continue;

        w *= (k - 1);

        graph[0][i].push_back({ i,1,w });
        graph[1][i].push_back({ i,0,w });
    }

    long long result = MinTime(graph);
    cout << result << '\n';
}