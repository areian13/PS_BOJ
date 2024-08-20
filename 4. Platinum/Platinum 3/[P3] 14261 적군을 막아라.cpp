#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cassert>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v;
    int c, f;
    Edge* rev;

    Edge() : Edge(-1, 0) {}
    Edge(int v, int c) : v(v), c(c), f(0), rev(nullptr) {}

    int Spare()
    {
        if (c == INT_MAX)
            return INT_MAX;
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

    return (level[t] != INT_MAX);
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

        if ((int)edge->Spare() <= 0 || level[v] != level[u] + 1)
            continue;

        int tFlow = GetFlow(v, t, min(flow, edge->Spare()), work, level, graph);
        if (tFlow == 0)
            continue;

        edge->AddFlow(tFlow);
        return tFlow;
    }
    return 0;
}

bool CanProtect(int s, int t, int k, vector<vector<Edge*>>& graph)
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

        if (result > k)
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge*>> graph(n * 2);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if (a == -1)
            continue;

        int u = i * 2;
        Edge::AddEdge(u, u + 1, a, a, graph);
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u = (u - 1) * 2;
        v = (v - 1) * 2;

        Edge::AddEdge(u + 1, v, INT_MAX, 0, graph);
        Edge::AddEdge(v + 1, u, INT_MAX, 0, graph);
    }

    int s = 0 * 2 + 1, t = (n - 1) * 2;
    string result = (CanProtect(s, t, k, graph) ? "YES" : "NO");
    cout << result << '\n';
    Edge::DeleteEdge(graph);
}