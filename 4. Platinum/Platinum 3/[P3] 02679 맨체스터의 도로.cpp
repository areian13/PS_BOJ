#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

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

int MaxCar(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    vector<int> dist(n, 0);
    dist[s] = INT_MAX;

    auto comp = [](const Edge& a, const Edge& b)
        {
            return a.c < b.c;
        };
    priority_queue<Edge, vector<Edge>, decltype(comp)> PQ(comp);
    PQ.push({ s,dist[s] });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().c;
        PQ.pop();

        if (dist[u] > w)
            continue;

        for (Edge* edge : graph[u])
        {
            int v = edge->v;
            int nw = min(w, edge->c);

            if (dist[v] >= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }
    return dist[t];
}

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

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, e, a, b;
        cin >> n >> e >> a >> b;

        vector<vector<Edge*>> graph(n);
        for (int i = 0; i < e; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            Edge::AddEdge(u, v, w, 0, graph);
        }

        lf(3);
        double result = (double)MaxFlow(a, b, graph) / MaxCar(a, b, graph);
        cout << result << '\n';

        for (auto& edges : graph)
        {
            for (Edge* edge : edges)
                delete edge;
        }
    }
}