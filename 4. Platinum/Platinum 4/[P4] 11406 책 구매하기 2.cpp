#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
    void AddFlow(int f)
    {
        this->f += f;
        rev->f -= f;
    }
};

int MaxBook(int s, int t, vector<vector<Edge*>>& graph)
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

    vector<vector<Edge*>> graph(n + m + 2);
    int s = n + m;
    int t = s + 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        int u = i;
        Edge* e1 = new Edge(t, a);
        Edge* e2 = new Edge(u, 0);
        e1->rev = e2;
        e2->rev = e1;
        graph[u].push_back(e1);
        graph[t].push_back(e2);
    }

    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;

        int u = n + i;

        Edge* e1 = new Edge(u, b);
        Edge* e2 = new Edge(s, 0);
        e1->rev = e2;
        e2->rev = e1;
        graph[s].push_back(e1);
        graph[u].push_back(e2);
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c;
            cin >> c;

            int u = n + i;
            int v = j;

            Edge* e1 = new Edge(v, c);
            Edge* e2 = new Edge(u, 0);
            e1->rev = e2;
            e2->rev = e1;
            graph[u].push_back(e1);
            graph[v].push_back(e2);
        }
    }

    int result = MaxBook(s, t, graph);
    cout << result << '\n';

    for (int u = 0; u < n + m + 2; u++)
    {
        for (Edge* edge : graph[u])
            delete edge;
    }
}