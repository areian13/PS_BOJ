#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

struct Pos
{
    double x, y;

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

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

double MinDist(int s, int t, vector<vector<Edge>>& graph)
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

        if (dist[u] < w)
            continue;

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
    return dist[t];
}

int main()
{
    FastIO;

    Pos s, t;
    cin >> s.x >> s.y >> t.x >> t.y;

    int n;
    cin >> n;
    n += 2;

    vector<Pos> cannon(n);
    cannon[0] = s;
    cannon[1] = t;
    for (int i = 2; i < n; i++)
        cin >> cannon[i].x >> cannon[i].y;

    vector<vector<Edge>> graph(n);
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            if (u == v)
                continue;

            double dist = Pos::Dist(cannon[u], cannon[v]);
            
            double w = min(dist / 5.0, (u < 2 ? DBL_MAX : fabs(dist - 50.0) / 5.0 + 2.0));
            graph[u].push_back({ v,w });
        }
    }

    lf(3);
    double result = MinDist(0, 1, graph);
    cout << result << '\n';
}