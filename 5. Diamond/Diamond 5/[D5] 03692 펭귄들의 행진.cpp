#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

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
    int c, f;
    Edge* rev;

    Edge() : Edge(-1, 0) {}
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
        for (auto edges : graph)
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

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        double d;
        cin >> n >> d;

        vector<Point> points(n);
        vector<vector<Edge*>> graph(n * 2 + 1);
        int s = n * 2;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y, f, c;
            cin >> x >> y >> f >> c;

            points[i] = { x,y };

            int u = i * 2;
            Edge::AddEdge(s, u, f, graph);
            Edge::AddEdge(u, u + 1, c, graph);

            sum += f;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                double dist = Point::Dist(points[i], points[j]);
                if (dist <= d)
                    Edge::AddEdge(i * 2 + 1, j * 2, INT_MAX, graph);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            for (auto edges : graph)
            {
                for (Edge* edge : edges)
                    edge->f = 0;
            }

            if (MaxFlow(s, i * 2, graph) == sum)
                result.push_back(i);
        }

        if (result.empty())
            cout << -1 << '\n';
        else
        {
            for (int x : result)
                cout << x << ' ';
            cout << '\n';
        }

        Edge::DeleteEdge(graph);
    }
}