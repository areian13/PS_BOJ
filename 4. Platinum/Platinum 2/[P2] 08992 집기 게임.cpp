#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Line
{
    int x1, y1, x2, y2, d;
};

struct Edge
{
    int v;
    int c, f, d;
    Edge* rev;

    Edge() : Edge(-1, 0, 0) {}
    Edge(int v, int c, int d) : v(v), c(c), f(0), d(d), rev(nullptr) {}

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

    static void AddEdge(int u, int v, int c1, int d1, int c2, int d2,
        vector<vector<Edge*>>& graph)
    {
        Edge* e1 = new Edge(v, c1, d1);
        Edge* e2 = new Edge(u, c2, d2);
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

bool IsCross(Line& w, Line& h)
{
    if (h.x1 < min(w.x1, w.x2) || h.x1 > max(w.x1, w.x2))
        return false;
    if (w.y1 < min(h.y1, h.y2) || w.y1 > max(h.y1, h.y2))
        return false;
    return true;
}

array<int, 2> MCMF(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    array<int, 2> result = { 0,0 };
    while (true)
    {
        vector<int> p(n, -1);
        vector<int> dist(n, INT_MIN);
        vector<Edge*> path(n);
        queue<int> Q;
        vector<bool> inQ(n, false);

        dist[s] = 0;
        Q.push(s);
        inQ[s] = true;

        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            inQ[u] = false;

            for (Edge* edge : graph[u])
            {
                int v = edge->v;
                int nd = dist[u] + edge->d;

                if (edge->Spare() <= 0 || dist[v] >= nd)
                    continue;

                dist[v] = nd;
                p[v] = u;
                path[v] = edge;

                if (!inQ[v])
                {
                    Q.push(v);
                    inQ[v] = true;
                }
            }
        }

        if (p[t] == -1)
            break;

        int flow = INT_MAX;
        for (int i = t; i != s; i = p[i])
            flow = min(flow, path[i]->Spare());
        int cost = 0;
        for (int i = t; i != s; i = p[i])
        {
            cost += flow * path[i]->d;
            path[i]->AddFlow(flow);
        }
        result[1] += cost;
        result[0] += flow;
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
        int n, m;
        cin >> n >> m;

        vector<vector<Edge*>> graph(n + m + 2);
        int s = n + m, t = s + 1;

        vector<Line> w(n);
        for (int i = 0; i < n; i++)
        {
            int x1, y1, x2, y2, d;
            cin >> x1 >> y1 >> x2 >> y2 >> d;

            w[i] = { x1,y1,x2,y2,d };

            int u = i;
            Edge::AddEdge(s, u, 1, 0, 0, 0, graph);
        }

        vector<Line> h(m);
        for (int i = 0; i < m; i++)
        {
            int x1, y1, x2, y2, d;
            cin >> x1 >> y1 >> x2 >> y2 >> d;

            h[i] = { x1,y1,x2,y2,d };

            int v = i + n;
            Edge::AddEdge(v, t, 1, 0, 0, 0, graph);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!IsCross(w[i], h[j]))
                    continue;

                int u = i;
                int v = j + n;
                int d = w[i].d * h[j].d;
                Edge::AddEdge(u, v, 1, d, 0, -d, graph);
            }
        }

        array<int, 2> result = MCMF(s, t, graph);
        cout << result[0] << ' ' << result[1] << '\n';
        Edge::DeleteEdge(graph);
    }
}