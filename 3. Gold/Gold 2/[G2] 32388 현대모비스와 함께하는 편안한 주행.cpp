#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);

using namespace std;

struct Point
{
    int x, y;

    static double Dist(const Point& a, const Point& b)
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
};

double MinStress(int s, int t, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<double> dist(n, DBL_MAX);
    dist[s] = 0;

    auto comp = [](const Edge& a, const Edge& b)
        {
            return a.w > b.w;
        };

    priority_queue<Edge, vector<Edge>, decltype(comp)> PQ(comp);
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

    Point p0 = { 0,0 }, p1;
    int n;
    cin >> p1.x >> p1.y >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    vector<vector<Edge>> graph(n + 2);
    int s = n, t = s + 1;
    graph[s].push_back({ t,Point::Dist(p0, p1) });

    for (int i = 0; i < n; i++)
    {
        graph[s].push_back({ i,max(Point::Dist(p0, points[i]) - 1, 0.0) });
        graph[i].push_back({ t,max(Point::Dist(points[i], p1) - 1, 0.0) });

        for (int j = i + 1; j < n; j++)
        {
            double w = max(Point::Dist(points[i], points[j]) - 2, 0.0);
            graph[i].push_back({ j,w });
            graph[j].push_back({ i,w });
        }
    }

    lf(9);
    double result = MinStress(s, t, graph);
    cout << result << '\n';
}