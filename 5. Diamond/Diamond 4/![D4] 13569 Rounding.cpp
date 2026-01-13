#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Edge
{
    int v;
    int c, lb, f0, f;
    Edge* rev;

    Edge() : Edge(-1, 0, 0) {}
    Edge(int v, int c, int lb) : v(v), c(c), lb(lb), f0(0), f(0), rev(nullptr) {}

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
};
struct MF
{
    int n;
    vector<vector<Edge*>> graph;
    MF(int n) : n(n) { graph.resize(n); }
    ~MF()
    {
        for (auto& edges : graph)
        {
            for (Edge* edge : edges)
                delete edge;
        }
    }

    int GetMF(int s, int t)
    {
        int result = 0;
        while (true)
        {
            vector<int> level(n, -1);
            if (!CanGo(s, t, level))
                break;

            vector<int> work(n, 0);
            while (true)
            {
                int flow = GetFlow(s, t, INF, work, level);
                if (flow == 0)
                    break;
                result += flow;
            }
        }
        return result;
    }
    bool CanGo(int s, int t, vector<int>& level)
    {
        level[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (Edge* edge : graph[u])
            {
                int v = edge->v;
                if (edge->Spare() <= 0 || level[v] != -1)
                    continue;

                level[v] = level[u] + 1;
                q.push(v);
            }
        }
        return level[t] != -1;
    }
    int GetFlow(int u, int t, int flow, vector<int>& work, vector<int>& level)
    {
        if (u == t)
            return flow;

        for (int& i = work[u]; i < graph[u].size(); i++)
        {
            Edge* edge = graph[u][i];
            int v = edge->v;

            if (edge->Spare() <= 0 || level[v] != level[u] + 1)
                continue;

            int tFlow = GetFlow(v, t, min(flow, edge->Spare()), work, level);
            if (tFlow > 0)
            {
                edge->AddFlow(tFlow);
                return tFlow;
            }
        }
        return 0;
    }

    void AddEdge(int u, int v, int c, int lb = 0)
    {
        Edge* e1 = new Edge(v, c, lb);
        Edge* e2 = new Edge(u, 0, 0);
        e1->rev = e2;
        e2->rev = e1;
        graph[u].push_back(e1);
        graph[v].push_back(e2);
    }
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector data(n, vector(m, make_pair(0, 0)));
    vector<pair<int, int>> rsum(n), csum(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%d.%d ", &data[i][j].first, &data[i][j].second);
        scanf("%d.%d ", &rsum[i].first, &rsum[i].second);
    }
    for (int j = 0; j < m; j++)
        scanf("%d.%d ", &csum[j].first, &csum[j].second);


}