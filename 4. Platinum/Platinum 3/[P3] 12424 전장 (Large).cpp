#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <array>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 3

struct Edge
{
    int v;
    long long c, f, d;
    Edge* rev;

    Edge() : Edge(-1, 0, 0) {}
    Edge(int v, long long c, long long  d) : v(v), c(c), f(0), d(d), rev(nullptr) {}

    long long Spare()
    {
        return c - f;
    }
    void AddFlow(long long flow)
    {
        f += flow;
        rev->f -= flow;
    }

    static void AddEdge(int u, int v, long long  c1, long long  d1,
        long long c2, long long d2,
        vector<vector<Edge*>>& graph)
    {
        Edge* e1 = new Edge(v, c1, d1);
        Edge* e2 = new Edge(u, c2, d2);
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


array<long long, 2> MCMF(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    array<long long, 2> result = { 0,0 };
    while (true)
    {
        vector<int> p(n, -1);
        vector<long long> dist(n, LLONG_MIN);
        vector<Edge*> path(n);
        queue<int> Q;
        vector<bool> inQ(n, false);

        dist[s] = 0;
        Q.push(s);
        inQ[s] = true;

        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            inQ[u] = false;

            for (Edge* edge : graph[u])
            {
                int v = edge->v;
                long long nd = dist[u] + edge->d;

                if (edge->Spare() <= 0 || dist[v] >= nd)
                    continue;

                dist[v] = nd;
                p[v] = u;
                path[v] = edge;

                if (!inQ[v])
                {
                    Q.push(v);
                    inQ[v] = true;
                }
            }
        }

        if (p[t] == -1)
            break;

        long long flow = LLONG_MAX;
        for (int i = t; i != s; i = p[i])
            flow = min(flow, path[i]->Spare());
        for (int i = t; i != s; i = p[i])
        {
            result[1] += flow * path[i]->d;
            path[i]->AddFlow(flow);
        }
        result[0] += flow;
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int ti = 1; ti <= tc; ti++)
    {
        long long n;
        cin >> n;

        vector<vector<Edge*>> graph(MAX * 2 + 2);
        int s = MAX * 2, t = s + 1;
        for (int u = 0; u < MAX * 2; u++)
        {
            long long a;
            cin >> a;

            if (u < MAX)
                Edge::AddEdge(s, u, a, 0, 0, 0, graph);
            else
                Edge::AddEdge(u, t, a, 0, 0, 0, graph);
        }

        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                long long p;
                cin >> p;

                int u = i, v = j + MAX;
                Edge::AddEdge(u, v, LLONG_MAX, p, 0, -p, graph);
            }
        }

        array<long long, 2> result = MCMF(s, t, graph);
        printf("Case #%d: %lld\n", ti, result[1]);
        Edge::DeleteEdge(graph);
    }
}