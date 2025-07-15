#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

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

    MF(int n) : n(n), s(-1), t(-1)
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

    vector<Edge*> FullEdges()
    {
        int flow = MaxFlow();

        vector<bool> isVisited(n, false);
        queue<int> Q;
        isVisited[s] = true;
        Q.push(s);

        vector<Edge*> result;
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            for (Edge* edge : graph[u])
            {
                int v = edge->v;
                if (isVisited[v])
                    continue;
                if (edge->Spare() <= 0)
                {
                    if (edge->Spare() == 0)
                        result.push_back(edge);
                    continue;
                }

                Q.push(v);
                isVisited[v] = true;
            }
        }
        return result;
    }
};

bool CanGo(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    vector<bool> isVisited(n, false);
    queue<int> Q;
    isVisited[s] = true;
    Q.push(s);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (Edge* edge : graph[u])
        {
            int v = edge->v;

            if (isVisited[v] || edge->c == 0)
                continue;

            isVisited[v] = true;
            Q.push(v);
        }
    }
    return isVisited[t];
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    MF mf(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;

        mf.AddEdge(u, v, c);
        mf.AddEdge(u, v, c);
    }

    cin >> mf.s >> mf.t;
    mf.s--, mf.t--;

    vector<Edge*> full = mf.FullEdges();
    sort(full.begin(), full.end(),
        [](auto& a, auto& b) { return a->c < b->c; }
    );

    int result = 0;
    while (true)
    {
        Edge* minEdge = full.back();
        full.pop_back();

        int minC = minEdge->c;
        minEdge->c = 0;
        minEdge->rev->c = 0;

        if (!CanGo(mf.s, mf.t, mf.graph))
        {
            for (auto& edges : mf.graph)
            {
                for (Edge* edge : edges)
                    result += edge->c;
            }
            result /= 2;
            result += minC;
            break;
        }
    }
    cout << result << '\n';
}