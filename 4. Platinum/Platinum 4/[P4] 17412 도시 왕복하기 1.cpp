#include <iostream>
#include <climits>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Edge
{
    int v, c, f;
    Edge* rev;

    Edge() : Edge(-1, 0) {}
    Edge(int v, int c) : v(v), c(c), f(0), rev(nullptr) {}

    int Spare()
    {
        if (c == INF && f != INF)
            return INF;
        return c - f;
    }
    void AddFlow(int flow)
    {
        f += flow;
        rev->f -= flow;
    }
};
struct MF
{
    vector<vector<Edge*>> graph;
    int n, s, t;

    MF(int n, int s, int t) : n(n), s(s), t(t)
    {
        graph.resize(n);
    }
    ~MF()
    {
        for (auto& edges : graph)
        {
            for (Edge* edge : edges)
                delete edge;
        }
    }

    void AddEdge(int u, int v, int c)
    {
        Edge* e1 = new Edge(v, c);
        Edge* e2 = new Edge(u, 0);
        e1->rev = e2;
        e2->rev = e1;
        graph[u].push_back(e1);
        graph[v].push_back(e2);
    }

    bool CanGo(vector<int>& level)
    {
        queue<int> Q;
        Q.push(s);
        level[s] = 0;

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
    int GetFlow(int u, int flow, vector<int>& work, vector<int>& level)
    {
        if (u == t)
            return flow;

        for (int& i = work[u]; i < graph[u].size(); i++)
        {
            Edge* edge = graph[u][i];
            int v = edge->v;

            if (edge->Spare() <= 0 || level[v] != level[u] + 1)
                continue;

            int tFlow = GetFlow(v, min(flow, edge->Spare()), work, level);
            if (tFlow > 0)
            {
                edge->AddFlow(tFlow);
                return tFlow;
            }
        }
        return 0;
    }

    int MaxFlow()
    {
        int result = 0;
        while (true)
        {
            vector<int> level(n, -1);
            if (!CanGo(level))
                break;

            vector<int> work(n, 0);
            while (true)
            {
                int flow = GetFlow(s, INF, work, level);
                if (flow == 0)
                    break;
                result += flow;
            }
        }
        return result;
    }
};

int main()
{
    FastIO;

    int n, p;
    cin >> n >> p;

    MF mf(n, 0, 1);
    for (int i = 0; i < p; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        mf.AddEdge(u, v, 1);
    }

    int result = mf.MaxFlow();
    cout << result << '\n';
}