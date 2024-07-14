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

int MaxFlow(int s, int t, vector<vector<Edge*>>& graph, bool onlyRoute = false)
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

                if (onlyRoute && v == t)
                    return -1;
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

int CountImportantEdge(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    int flow = MaxFlow(s, t, graph);
    int result = 0;

    for (int u = 0; u < n; u++)
    {
        for (Edge* edge : graph[u])
        {
            if (edge->c == 0 || edge->Spare() != 0)
                continue;
            
            edge->c--;
            edge->AddFLow(-1);
            result += (MaxFlow(u, edge->v, graph, true) != -1);
            edge->c++;
            edge->AddFLow(+1);
        }
    }
    return result;
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<Edge*>> graph(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, c;
            cin >> u >> v >> c;
            u--, v--;

            Edge* e1 = new Edge(v, c);
            Edge* e2 = new Edge(u, 0);
            e1->rev = e2;
            e2->rev = e1;

            graph[u].push_back(e1);
            graph[v].push_back(e2);
        }

        int result = CountImportantEdge(0, n - 1, graph);
        cout << result << '\n';

        for (int u = 0; u < n; u++)
        {
            for (Edge* edge : graph[u])
                delete edge;
        }
    }
}