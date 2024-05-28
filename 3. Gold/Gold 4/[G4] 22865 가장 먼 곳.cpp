#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define FRIEND_NUM 3

struct Edge
{
    int v;
    int d;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.d > b.d;
    }
};

void Dijkstra(int x, vector<int>& dist, vector<vector<Edge>>& graph)
{
    dist[x] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ x,0 });

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
}

int FarthestPlace(vector<int>& x, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<vector<int>> dists(FRIEND_NUM, vector<int>(n, INT_MAX));
    for (int i = 0; i < FRIEND_NUM; i++)
        Dijkstra(x[i], dists[i], graph);

    Edge result = { -1,0 };
    for (int j = 0; j < n; j++)
    {
        int d = INT_MAX;
        for (int i = 0; i < FRIEND_NUM; i++)
            d = min(d, dists[i][j]);

        if (result.d < d)
            result = { j,d };
    }
    return result.v;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> x(FRIEND_NUM);
    for (int i = 0; i < FRIEND_NUM; i++)
    {
        cin >> x[i];
        x[i]--;
    }

    int m;
    cin >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;

        graph[u].push_back({ v,d });
        graph[v].push_back({ u,d });
    }

    int result = FarthestPlace(x, graph);
    cout << result + 1 << '\n';
}