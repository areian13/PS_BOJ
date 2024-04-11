#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int x, y;
};

struct Edge
{
    int v;
    double w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

double Dist(Pos& a, Pos& b)
{
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}

double GetMinWire(int s, int e, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<double> dist(n, DBL_MAX);
    dist[s] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        double w = PQ.top().w;
        PQ.pop();

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            double nw = w + edge.w;

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }
    return dist[e];
}

int main()
{
    FastIO;

    int n, w;
    double m;
    cin >> n >> w >> m;

    vector<Pos> pos(n);
    for (int i = 0; i < n; i++)
        cin >> pos[i].x >> pos[i].y;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < w; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back({ v,0 });
        graph[v].push_back({ u,0 });
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double w = Dist(pos[i], pos[j]);

            if (w > m)
                continue;

            graph[i].push_back({ j,w });
            graph[j].push_back({ i,w });
        }
    }

    int result = GetMinWire(0, n - 1, graph) * 1'000;
    cout << result << '\n';
}