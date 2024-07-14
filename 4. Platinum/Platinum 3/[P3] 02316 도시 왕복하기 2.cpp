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
    void AddFLow(int f)
    {
        this->f += f;
        rev->f -= f;
    }
};

int MaxWander(int s, int t, vector<vector<Edge*>>& graph)
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
                int w = edge->Spare();

                if (w <= 0 || p[v] != -1)
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
            path[i]->AddFLow(flow);
        result += flow;
    }
    return result;
}

int main()
{
    int n, p;
    cin >> n >> p;

    vector<vector<Edge*>> graph(n * 2);
    for (int i = 0; i < n; i++)
    {
        int u = i * 2;

        Edge* e1 = new Edge(u + 1, 1);
        Edge* e2 = new Edge(u, 0);
        e1->rev = e2;
        e2->rev = e1;

        graph[u].push_back(e1);
        graph[u + 1].push_back(e2);
    }

    for (int i = 0; i < p; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        u *= 2, v *= 2;

        Edge* e1 = new Edge(v, 1);
        Edge* e2 = new Edge(u + 1, 0);
        e1->rev = e2;
        e2->rev = e1;

        graph[u + 1].push_back(e1);
        graph[v].push_back(e2);

        e1 = new Edge(u, 1);
        e2 = new Edge(v + 1, 0);
        e1->rev = e2;
        e2->rev = e1;

        graph[v + 1].push_back(e1);
        graph[u].push_back(e2);
    }

    int s = (1 - 1) * 2 + 1;
    int t = (2 - 1) * 2;
    int result = MaxWander(s, t, graph);
    cout << result << '\n';

    for (int u = 0; u < n * 2; u++)
    {
        for (Edge* edge : graph[u])
            delete edge;
    }
}