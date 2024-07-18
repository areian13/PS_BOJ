#include <iostream>
#include <vector>
#include <climits>
#include <queue>

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

int MaxPig(int s, int t, vector<vector<Edge*>>& graph)
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

    int m, n;
    cin >> m >> n;

    vector<vector<Edge*>> graph((m + 1) * n + 2);
    int s = (m + 1) * n;
    int t = s + 1;
    for (int i = 0; i < m; i++)
    {
        int p;
        cin >> p;

        for (int j = 0; j < n; j++)
        {
            int v = i * n + j;
            int u = (j == 0 ? s : v - 1);
            int c = (j == 0 ? p : INT_MAX);

            Edge::AddEdge(u, v, c, 0, graph);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        vector<int> k(a);
        for (int j = 0; j < a; j++)
        {
            cin >> k[j];
            k[j]--;

            int u = k[j] * n + i;
            int v = m * n + i;
            Edge::AddEdge(u, v, INT_MAX, 0, graph);
        }

        int b;
        cin >> b;

        int u = m * n + i;
        Edge::AddEdge(u, t, b, 0, graph);

        if (i == n - 1)
            break;

        for (int j = 0; j < a; j++)
        {
            for (int l = 0; l < a; l++)
            {
                if (j == l)
                    continue;

                int u = k[j] * n + i;
                int v = k[l] * n + i + 1;
                Edge::AddEdge(u, v, INT_MAX, 0, graph);
            }
        }
    }

    int result = MaxPig(s, t, graph);
    cout << result << '\n';
}