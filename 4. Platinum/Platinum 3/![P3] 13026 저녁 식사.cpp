#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 20'000

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

    for (Edge* edge : graph[u])
    {
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

    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAX; i++)
    {
        if (!isPrime[i])
            continue;

        for (int j = 2; i * j <= MAX; j++)
            isPrime[i * j] = false;
    }

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<Edge*>> graph(n + 2);
    int s = n, t = s + 1;
    for (int i = 0; i < n; i++)
    {
        int u = i;
        if (a[i] % 2 == 0)
            Edge::AddEdge(s, u, 1, 0, graph);
        else
            Edge::AddEdge(u, t, 1, 0, graph);

        for (int j = i + 1; j < n; j++)
        {
            if (!isPrime[a[i] + a[j]])
                continue;

            int v = j * 2;
            Edge::AddEdge(u, v, 1, 1, graph);
        }
    }

    int flow = MaxFlow(s, t, graph);
    cout << flow << '\n';
    string result = (flow == n * 3 ? "Possible" : "Impossible");
    cout << result << '\n';
    Edge::DeleteEdge(graph);
}