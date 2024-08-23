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

    return level[t] != -1;
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

int MaxFlow(int s, int t, vector<vector<Edge*>>& graph)
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

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<vector<Edge*>> graph(n + 3 + 2);
        int s = n + 3, t = s + 1;
        for (int u = 0; u < n; u++)
            Edge::AddEdge(s, u, 1, 0, graph);

        for (int u = 0; u < 3; u++)
        {
            int a;
            cin >> a;

            int v = u + n;
            Edge::AddEdge(v, t, a, 0, graph);
        }

        for (int u = 0; u < 3; u++)
        {
            int m;
            cin >> m;

            int v = u + n;
            for (int j = 0; j < m; j++)
            {
                int u;
                cin >> u;
                u--;

                Edge::AddEdge(u, v, 1, 0, graph);
            }
        }

        int flow = MaxFlow(s, t, graph);
        cout << flow << '\n';
        for (int u = 0; u < n; u++)
        {
            for (Edge* edge : graph[u])
            {
                if (edge->Spare() != 0)
                    continue;

                char result = edge->v - n + 'A';
                if (!('A' <= result && result <= 'C'))
                    continue;

                cout << u + 1 << ' ' << result << '\n';
                break;
            }
        }
        Edge::DeleteEdge(graph);
    }
}