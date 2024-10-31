#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = (long long)(b.x - a.x) * (c.y - a.y)
            - (long long)(b.y - a.y) * (c.x - a.x);

        if (ccw < 0)
            return -1;
        if (ccw > 0)
            return +1;
        return 0;
    }
};

struct Line
{
    Point p1, p2;

    static bool IsIntersecting(const Line& a, const Line& b)
    {
        int ab1 = Point::CCW(a.p1, a.p2, b.p1);
        int ab2 = Point::CCW(a.p1, a.p2, b.p2);
        int ba1 = Point::CCW(b.p1, b.p2, a.p1);
        int ba2 = Point::CCW(b.p1, b.p2, a.p2);

        if (ab1 * ab2 < 0 && ba1 * ba2 < 0)
            return true;
        return (ab1 == 0 && OnSegment(b.p1, a))
            || (ab2 == 0 && OnSegment(b.p2, a))
            || (ba1 == 0 && OnSegment(a.p1, b))
            || (ba2 == 0 && OnSegment(a.p2, b));
    }
    static bool OnSegment(const Point& a, const Line& b)
    {
        return min(b.p1.x, b.p2.x) <= a.x && a.x <= max(b.p1.x, b.p2.x)
            && min(b.p1.y, b.p2.y) <= a.y && a.y <= max(b.p1.y, b.p2.y);
    }
};

struct Edge
{
    int v;
    int c, f;
    Edge* rev;

    Edge() : Edge(v, c) {}
    Edge(int v, int c) : v(v), c(c), f(0), rev(nullptr) {}

    int Spare()
    {
        if (c == INT_MAX && f != INT_MAX)
            return INT_MAX;
        return c - f;
    }
    void AddFlow(int flow)
    {
        f += flow;
        rev->f -= flow;
    }

    static void AddEdge(int u, int v, int c, vector<vector<Edge*>>& graph)
    {
        Edge* e1 = new Edge(v, c);
        Edge* e2 = new Edge(u, 0);
        e1->rev = e2;
        e2->rev = e1;
        graph[u].push_back(e1);
        graph[v].push_back(e2);
    }
    static void DeleteEdge(vector<vector<Edge*>>& graph)
    {
        for (auto& edges : graph)
        {
            for (Edge* edge : edges)
                delete edge;
        }
    }
};

int MaxFlow(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    int result = 0;
    while (true)
    {
        vector<int> p(n, -1);
        vector<Edge*> path(n);
        queue<int> Q;
        Q.push(s);

        while (!Q.empty() && p[t] == -1)
        {
            int u = Q.front();
            Q.pop();

            for (Edge* edge : graph[u])
            {
                int v = edge->v;

                if (edge->Spare() <= 0 || p[v] != -1)
                    continue;

                p[v] = u;
                path[v] = edge;
                Q.push(v);

                if (v == t)
                    break;
            }
        }

        if (p[t] == -1)
            break;

        int flow = INT_MAX;
        for (int i = t; i != s; i = p[i])
            flow = min(flow, path[i]->Spare());
        
        result += flow;
        for (int i = t; i != s; i = p[i])
            path[i]->AddFlow(flow);
    }
    return result;
}

int main()
{
    FastIO;

    int n, k, h, m;
    cin >> n >> k >> h >> m;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    vector<Line> walls(n);
    for (int i = 0; i < n; i++)
        walls[i] = { points[i], points[(i + 1) % n] };

    vector<vector<Edge*>> graph(h + m + 2);
    int s = h + m, t = s + 1;

    vector<Point> holes(h);
    for (int i = 0; i < h; i++)
    {
        Edge::AddEdge(i, t, k, graph);
        cin >> holes[i].x >> holes[i].y;
    }

    for (int i = 0; i < m; i++)
    {
        Edge::AddEdge(s, h + i, 1, graph);

        Point mouse;
        cin >> mouse.x >> mouse.y;

        for (int j = 0; j < h; j++)
        {
            Line l = { mouse,holes[j] };
            bool canGo = true;
            for (int k = 0; k < n; k++)
            {
                if (Line::IsIntersecting(l, walls[k]) && !Line::OnSegment(holes[j], walls[k]))
                {
                    canGo = false;
                    break;
                }
            }

            if (canGo)
                Edge::AddEdge(h + i, j, 1, graph);
        }
    }

    int flow = MaxFlow(s, t, graph);
    string result = (flow == m ? "Possible" : "Impossible");
    cout << result << '\n';
    Edge::DeleteEdge(graph);
}