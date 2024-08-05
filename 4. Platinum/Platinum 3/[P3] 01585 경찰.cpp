#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, c, f, d;
    Edge* rev;

    Edge() : Edge(-1, 0, 0) {}
    Edge(int v, int c, int d) : v(v), c(c), f(0), d(d), rev(nullptr) {}

    int Spare()
    {
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

array<int, 2> MCMF(int s, int t, vector<vector<Edge*>>& graph, bool isMin)
{
    for (auto& edges : graph)
    {
        for (Edge* edge : edges)
            edge->f = 0;
    }

    int n = graph.size();

    array<int, 2> result = { 0,0 };
    while (true)
    {
        vector<int> p(n, -1), dist(n, INT_MAX);
        dist[s] = 0;
        vector<Edge*> path(n);

        queue<int> Q;
        Q.push(s);

        vector<bool> inQ(n, false);
        inQ[s] = true;

        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            inQ[u] = false;

            for (Edge* edge : graph[u])
            {
                int v = edge->v;
                int nd = dist[u] + edge->d * (isMin ? +1 : -1);

                if (edge->Spare() <= 0 || dist[v] <= nd)
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

        for (int i = t; i != s; i = p[i])
        {
            result[1] += path[i]->d;
            path[i]->AddFlow(+1);
        }
        result[0]++;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<Edge*>> graph(n * 2 + 2);
    vector<int> in(n);
    int s = n * 2;
    for (int u = 0; u < n; u++)
    {
        cin >> in[u];
        Edge::AddEdge(s, u, 1, 0, 0, 0, graph);
    }

    vector<int> out(n);
    int t = s + 1;
    for (int v = 0; v < n; v++)
    {
        cin >> out[v];
        Edge::AddEdge(v + n, t, 1, 0, 0, 0, graph);
    }

    int l, f;
    cin >> l >> f;

    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            if (out[v] <= in[u])
                continue;

            int c = max(l - (out[v] - in[u]), 0);
            int d = min(c * c, f);
            Edge::AddEdge(u, v + n, 1, d, 0, -d, graph);
        }
    }

    array<int, 2> minCost = MCMF(s, t, graph, true);
    array<int, 2> maxCost = MCMF(s, t, graph, false);

    if (minCost[0] != n || maxCost[0] != n)
        cout << -1 << '\n';
    else
        cout << minCost[1] << ' ' << maxCost[1] << '\n';
    Edge::DeleteEdge(graph);
}