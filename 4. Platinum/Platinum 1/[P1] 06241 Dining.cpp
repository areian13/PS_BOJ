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

    static void AddEdge(int u, int v, int c1, int c2, vector<vector<Edge*>>& graph)
    {
        Edge* e1 = new Edge(v, c1);
        Edge* e2 = new Edge(u, c2);
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

bool CanGo(int s, int t, vector<int>& level, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    level[s] = 0;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (Edge* edge : graph[u])
        {
            int v = edge->v;

            if (edge->Spare() <= 0 || level[v] != INT_MAX)
                continue;

            level[v] = level[u] + 1;
            Q.push(v);
        }
    }

    return (level[t] != -1);
}

int GetFlow(int u, int t, int flow, vector<int>& work,
    vector<int>& level, vector<vector<Edge*>>& graph)
{
    if (u == t)
        return flow;

    for (int& i = work[u]; i < graph[u].size(); i++)
    {
        Edge* edge = graph[u][i];
        int v = edge->v;

        if (edge->Spare() <= 0 || level[v] != level[u] + 1)
            continue;

        int tFlow = GetFlow(v, t, min(flow, edge->Spare()), work, level, graph);
        if (tFlow == 0)
            continue;

        edge->AddFlow(tFlow);
        return tFlow;
    }
    return 0;
}

int HappyCow(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    int result = 0;
    while (true)
    {
        vector<int> level(n, INT_MAX);
        if (!CanGo(s, t, level, graph))
            break;

        vector<int> work(n, 0);
        int flow = GetFlow(s, t, INT_MAX, work, level, graph);
        if (flow == 0)
            break;
        result += flow;
    }
    return result;
}

int main()
{
    FastIO;

    int n, f, d;
    cin >> n >> f >> d;

    vector<vector<Edge*>> graph(n * 2 + f + d + 2);
    int s = n * 2 + f + d;
    for (int i = 0; i < f; i++)
    {
        int u = n * 2 + i;
        Edge::AddEdge(s, u, 1, 0, graph);
    }

    int t = s + 1;
    for (int i = 0; i < d; i++)
    {
        int v = n * 2 + f + i;
        Edge::AddEdge(v, t, 1, 0, graph);
    }

    for (int i = 0; i < n; i++)
    {
        int u = i * 2;
        Edge::AddEdge(u, u + 1, 1, 0, graph);

        int fi, di;
        cin >> fi >> di;

        for (int j = 0; j < fi; j++)
        {
            int v;
            cin >> v;
            v += n * 2 - 1;

            Edge::AddEdge(v, u, 1, 0, graph);
        }

        for (int j = 0; j < di; j++)
        {
            int v;
            cin >> v;
            v += n * 2 + f - 1;

            Edge::AddEdge(u + 1, v, 1, 0, graph);
        }
    }

    int result = HappyCow(s, t, graph);
    cout << result << '\n';
    Edge::DeleteEdge(graph);
}