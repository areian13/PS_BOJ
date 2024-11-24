#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 365

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

int MaxCost(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    int result = 0;
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

        int sum = 0;
        for (int i = t; i != s; i = p[i])
        {
            sum += path[i]->d * flow;
            path[i]->AddFlow(flow);
        }

        if (sum < 0)
            break;
        result += sum;
    }
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<vector<Edge*>> graph(MAX * 2 + 2);
        int s = MAX * 2, t = s + 1;
         
        int result = MaxCost(s, t, graph);
        cout << result << '\n';
        Edge::DeleteEdge(graph);
    }
}