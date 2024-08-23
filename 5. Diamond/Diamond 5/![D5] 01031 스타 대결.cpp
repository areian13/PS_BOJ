#include <iostream>
#include <vector>
#include <climits>
#include <queue>
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
    static void InitEdge(vector<vector<Edge*>>& graph)
    {
        for (auto& edges : graph)
        {
            for (Edge* edge : edges)
                edge->f = 0;
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
        //for (int& i = work[u]; i >= 0; i--)
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

int MaxFlow(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    int result = 0;
    while (true)
    {
        vector<int> level(n, INT_MAX);
        if (!CanGo(s, t, level, graph))
            break;

        vector<int> work(n, 0);
        //for (int u = 0; u < n; u++)
        //    work[u] = graph[u].size() - 1;
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

    int n, m;
    cin >> n >> m;

    vector<vector<Edge*>> graph(n + m + 2);
    int s = n + m, t = s + 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;

        int u = i;
        Edge::AddEdge(s, u, a, 0, graph);

        for (int j = 0; j < m; j++)
        {
            int v = j + n;
            Edge::AddEdge(u, v, 1, 0, graph);
        }
    }
    //reverse(graph[s].begin(), graph[s].end());

    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        sum += a;

        int v = i + n;
        Edge::AddEdge(v, t, a, 0, graph);
    }

    int flow = MaxFlow(s, t, graph);
    if (flow != sum / 2)
        cout << -1 << '\n';
    else
    {
        while (true)
        {
            bool isChanged = false;
            for (int u = 0; u < n; u++)
            {
                for (Edge* edge : graph[u])
                {
                    if (edge->v == s || edge->Spare() > 0)
                        continue;

                    Edge::InitEdge(graph);
                    edge->c = 0;
                    int f = MaxFlow(s, t, graph);
                    cout << f << '\n';
                    if (f == flow)
                    {
                        isChanged = true;
                        continue;
                    }

                    edge->c = 1;
                }
                if (isChanged)
                    break;
            }
            if (!isChanged)
                break;
        }

        Edge::InitEdge(graph);
        MaxFlow(s, t, graph);
        for (int u = 0; u < n; u++)
        {
            for (Edge* edge : graph[u])
            {
                if (edge->v == s)
                    continue;

                cout << (edge->Spare() == 0);
            }
            cout << '\n';
        }
    }
}