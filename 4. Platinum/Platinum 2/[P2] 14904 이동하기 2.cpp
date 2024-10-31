#include <iostream>
#include <vector>
#include <climits>
#include <array>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const array<int, 2> dr = { 0,1 };
const array<int, 2> dc = { 1,0 };

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

    static void AddEdge(int u, int v, int c, int d,
        vector<vector<Edge*>>& graph)
    {
        Edge* e1 = new Edge(v, c, d);
        Edge* e2 = new Edge(u, 0, -d);
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

array<int, 2> MCMF(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    array<int, 2> result = { 0,0 };
    while (true)
    {
        vector<int> p(n, -1);
        vector<Edge*> path(n);
        vector<int> dist(n, INT_MIN);
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

                if (edge->Spare() <= 0 || nd <= dist[v])
                    continue;

                p[v] = u;
                path[v] = edge;
                dist[v] = nd;

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

        result[0] += flow;
        for (int i = t; i != s; i = p[i])
        {
            result[1] += flow * path[i]->d;
            path[i]->AddFlow(flow);
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<vector<Edge*>> graph(n * n * 2 + 1);
    int s = n * n * 2, t = n * n * 2 - 1;
    Edge::AddEdge(s, 0, min(k, 1), 0, graph);
    Edge::AddEdge(s, 1, max(k - 1, 0), 0, graph);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int d;
            cin >> d;

            int u = (i * n + j) * 2;
            Edge::AddEdge(u, u + 1, 1, d, graph);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int u = (i * n + j) * 2;
            for (int d = 0; d < 2; d++)
            {
                int nr = i + dr[d];
                int nc = j + dc[d];

                if (nr >= n || nc >= n)
                    continue;

                int v = (nr * n + nc) * 2;
                Edge::AddEdge(u + 1, v, min(k, 1), 0, graph);
                Edge::AddEdge(u + 1, v + 1, max(k - 1, 0), 0, graph);
            }
        }
    }

    array<int, 2> result = MCMF(s, t, graph);
    cout << result[1] << '\n';
    Edge::DeleteEdge(graph);
}