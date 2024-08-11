#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v;
    long long c, f;
    Edge* rev;

    Edge() : Edge(-1, 0) {}
    Edge(int v, long long c) : v(v), c(c), f(0), rev(nullptr) {}

    long long Spare()
    {
        return c - f;
    }
    void AddFlow(long long flow)
    {
        f += flow;
        rev->f -= flow;
    }

    static void AddEdge(int u, int v, long long c1, long long c2, vector<vector<Edge*>>& graph)
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

    return level[t] != INT_MAX;
}

long long GetFlow(int u, int t, long long flow, vector<int>& work,
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

        long long tFlow = GetFlow(v, t, min(flow, edge->Spare()), work, level, graph);
        if (tFlow > 0)
        {
            edge->AddFlow(tFlow);
            return tFlow;
        }
    }
    return 0;
}

long long MaxFlow(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    long long result = 0;
    while (true)
    {
        vector<int> level(n, INT_MAX);
        if (!CanGo(s, t, level, graph))
            break;

        vector<int> work(n, 0);
        while (true)
        {
            long long flow = GetFlow(s, t, LLONG_MAX, work, level, graph);
            if (flow == 0)
                break;
            result += flow;
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
    vector<int> c(n + m);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];

        int u = i;
        Edge::AddEdge(u, t, LLONG_MAX, 0, graph);
    }

    for (int i = 0; i < m; i++)
    {
        int v = n + i;

        cin >> c[v];
        Edge::AddEdge(s, v, c[v], 0, graph);
    }

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;

        int u = n + i;
        for (int j = 0; j < k; j++)
        {
            int v;
            cin >> v;
            v--;

            Edge::AddEdge(u, v, c[v], 0, graph);
        }
    }

    long long result = MaxFlow(s, t, graph);
    cout << result << '\n';
    Edge::DeleteEdge(graph);
}