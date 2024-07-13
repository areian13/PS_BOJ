#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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

int HappyCow(int s, int t, vector<vector<Edge*>>& graph)
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
    int s = 0;
    for (int u = 1; u <= n; u++)
    {
        Edge* e1 = new Edge(u, 1);
        Edge* e2 = new Edge(s, 0);
        e1->rev = e2;
        e2->rev = e1;

        graph[s].push_back(e1);
        graph[u].push_back(e2);

        int k;
        cin >> k;

        for (int i = 0; i < k; i++)
        {
            int v;
            cin >> v;
            v += n;

            Edge* e1 = new Edge(v, 1);
            Edge* e2 = new Edge(u, 0);
            e1->rev = e2;
            e2->rev = e1;

            graph[u].push_back(e1);
            graph[v].push_back(e2);
        }
    }

    int t = n + m + 1;
    for (int v = n + 1; v <= n + m; v++)
    {
        Edge* e1 = new Edge(t, 1);
        Edge* e2 = new Edge(v, 0);
        e1->rev = e2;
        e2->rev = e1;

        graph[v].push_back(e1);
        graph[t].push_back(e2);
    }

    int result = HappyCow(s, t, graph);
    cout << result << '\n';

    for (int u = 0; u <= n + m + 1; u++)
    {
        for (Edge* edge : graph[u])
            delete edge;
    }
}