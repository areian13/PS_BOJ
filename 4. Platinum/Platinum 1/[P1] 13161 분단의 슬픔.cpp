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

            if (edge->Spare() <= 0 || level[v] != -1)
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
        if (tFlow > 0)
        {
            edge->AddFlow(tFlow);
            return tFlow;
        }
    }

    return 0;
}

int MinSad(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    int result = 0;
    while (true)
    {
        vector<int> level(n, -1);
        if (!CanGo(s, t, level, graph))
            break;

        vector<int> work(n, 0);
        while (true)
        {
            int flow = GetFlow(s, t, INT_MAX, work, level, graph);
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

    int n;
    cin >> n;

    vector<vector<Edge*>> graph(n + 2);
    int s = n, t = s + 1;
    for (int u = 0; u < n; u++)
    {
        int p;
        cin >> p;

        if (p == 1)
            Edge::AddEdge(s, u, INT_MAX, 0, graph);
        else if (p == 2)
            Edge::AddEdge(u, t, INT_MAX, 0, graph);
    }

    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            int c;
            cin >> c;

            if (u >= v)
                continue;

            Edge::AddEdge(u, v, c, c, graph);
        }
    }

    int result = MinSad(s, t, graph);
    cout << result << '\n';

    vector<bool> isVisited(n + 2, false);
    isVisited[s] = true;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (Edge* edge : graph[u])
        {
            int v = edge->v;

            if (edge->Spare() <= 0 || isVisited[v])
                continue;

            isVisited[v] = true;
            Q.push(v);
        }
    }

    for (int u = 0; u < n; u++)
    {
        if (isVisited[u])
            cout << u + 1 << ' ';
    }
    cout << '\n';

    for (int v = 0; v < n; v++)
    {
        if (!isVisited[v])
            cout << v + 1 << ' ';
    }
    cout << '\n';

    Edge::DeleteEdge(graph);
}