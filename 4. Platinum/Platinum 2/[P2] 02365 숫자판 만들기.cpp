#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

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
        if (c == INT_MAX && f != INT_MAX)
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

    int n;
    cin >> n;

    vector<vector<Edge*>> graph(n * 2 + 2);
    int s = n * 2, t = s + 1;
    int start = 0, end = 0;
    int flowSum = 0;
    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;

        end = max(end, r);
        flowSum += r;

        int u = i;
        Edge::AddEdge(s, u, r, 0, graph);
    }

    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;

        end = max(end, c);

        int v = i + n;
        Edge::AddEdge(v, t, c, 0, graph);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int u = i;
            int v = j + n;
            Edge::AddEdge(u, v, -1, 0, graph);
        }
    }

    int result = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        for (int u = 0; u < n * 2 + 2; u++)
        {
            for (Edge* edge : graph[u])
            {
                int v = edge->v;
                edge->f = 0;

                if (u < n && v != s && v != t)
                    edge->c = mid;
            }
        }

        int flow = MaxFlow(s, t, graph);

        if (flow != flowSum)
            start = mid + 1;
        else
        {
            result = min(result, mid);
            end = mid - 1;
        }
    }

    for (int u = 0; u < n * 2 + 2; u++)
    {
        for (Edge* edge : graph[u])
        {
            int v = edge->v;
            edge->f = 0;

            if (u < n && v != s && v != t)
                edge->c = result;
        }
    }
    MaxFlow(s, t, graph);

    cout << result << '\n';
    for (int u = 0; u < n; u++)
    {
        for (Edge* edge : graph[u])
        {
            if (edge->v != s)
                cout << edge->f << ' ';
        }
        cout << '\n';
    }
    Edge::DeleteEdge(graph);
}