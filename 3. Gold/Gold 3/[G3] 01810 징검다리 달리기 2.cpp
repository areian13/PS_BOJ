#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int x, y;

    static double Dist(const Pos& a, const Pos& b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;

        return sqrt(dx * dx + dy * dy);
    }
};

struct Edge
{
    int v;
    double w;
    Pos p;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

int MinDist(int f, vector<vector<Edge>>& graph)
{
    int n = graph.size() - 1;

    vector<double> dist(n + 1, DBL_MAX);
    dist[n] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ n,0,0,0 });

    double result = DBL_MAX;
    while (!PQ.empty())
    {
        int u = PQ.top().v;
        double w = PQ.top().w;
        int y = PQ.top().p.y;
        PQ.pop();

        if (y == f)
            result = min(result, w);
        if (dist[u] < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            double nw = w + edge.w;

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw,edge.p });
        }
    }
    if (result == DBL_MAX)
        return -1;
    return result + 0.5;
}

int main()
{
    FastIO;

    int n, f;
    cin >> n >> f;

    vector<Pos> pos(n + 1);
    for (int i = 0; i < n; i++)
        cin >> pos[i].x >> pos[i].y;
    pos[n] = { 0,0 };

    vector<vector<Edge>> graph(n + 1);
    for (int u = 0; u < n; u++)
    {
        for (int v = u + 1; v <= n; v++)
        {
            Pos& p1 = pos[u];
            Pos& p2 = pos[v];

            if (abs(p1.x - p2.x) > 2 || abs(p1.y - p2.y) > 2)
                continue;

            double w = Pos::Dist(p1, p2);
            graph[u].push_back({ v,w,p2 });
            graph[v].push_back({ u,w,p1 });
        }
    }

    int result = MinDist(f, graph);
    cout << result << '\n';
}