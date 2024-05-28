#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

void RouteTable(vector<vector<Edge>>& graph, vector<vector<int>>& result)
{
    int n = graph.size();

    for (int i = 0; i < n; i++)
    {
        vector<int> dist(n, INT_MAX);
        dist[i] = 0;

        priority_queue<Edge> PQ;
        PQ.push({ -1,i,0 });

        while (!PQ.empty())
        {
            int p = PQ.top().u;
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

                int np = (p == -1 ? v : p);
                result[i][v] = np + 1;

                dist[v] = nw;
                PQ.push({ np,v,nw });
            }
        }
    }
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

        graph[u].push_back({ u,v,w });
        graph[v].push_back({ v,u,w });
    }

    vector<vector<int>> result(n, vector<int>(n, -1));
    RouteTable(graph, result);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << '-' << ' ';
            else
                cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
}