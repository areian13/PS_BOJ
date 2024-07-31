#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, c, f;
    Edge* rev;

    Edge() : Edge(-1, 0) {}
    Edge(int v, int c) : v(v), c(c), f(0), rev(nullptr) {}

    int Spare()
    {
        return c - f;
    }
    void AddFlow(int flow)
    {
        f += flow;
        rev->f -= flow;
    }

    static void AddEdge(int u, int v, int c2, int c1, vector<vector<Edge*>>& graph)
    {
        Edge* e1 = new Edge(v, c2);
        Edge* e2 = new Edge(u, c1);
        e1->rev = e2;
        e2->rev = e1;
        graph[u].push_back(e1);
        graph[v].push_back(e2);
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
        for (int i = t; i != s; i = p[i])
            path[i]->AddFlow(flow);
        result += flow;
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<Edge*>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        Edge::AddEdge(u, v, w, w, graph);
    }

    int result = MaxFlow(0, n - 1, graph);
    cout << result << '\n';

    for (auto& edges : graph)
    {
        for (Edge* edge : edges)
            delete edge;
    }
}