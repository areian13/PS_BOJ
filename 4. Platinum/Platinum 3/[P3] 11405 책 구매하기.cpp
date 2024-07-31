#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, c, f, d;
    Edge* rev;

    Edge () : Edge(-1, 0, 0) {}
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

    static void AddEdge(int u, int v, int c1, int c2, int d1, int d2,
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

int MinCost(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    int result = 0;
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
                int nd = dist[u] + edge->d;

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

        int flow = INT_MAX;
        for (int i = t; i != s; i = p[i])
            flow = min(flow, path[i]->Spare());
        for (int i = t; i != s; i = p[i])
        {
            result += flow * path[i]->d;
            path[i]->AddFlow(flow);
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<Edge*>> graph(n + m + 2);
    int s = n + m, t = s + 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        
        int u = i;
        Edge::AddEdge(s, u, a, 0, 0, 0, graph);
    }

    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;

        int u = i + n;
        Edge::AddEdge(u, t, b, 0, 0, 0, graph);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c;
            cin >> c;

            int u = j;
            int v = i + n;
            Edge::AddEdge(u, v, INT_MAX, 0, c, -c, graph);
        }
    }

    int result = MinCost(s, t, graph);
    cout << result << '\n';
    Edge::DeleteEdge(graph);
}