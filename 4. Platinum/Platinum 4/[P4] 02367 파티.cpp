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
        return c - f;
    }
    void AddFLow(int f)
    {
        this->f += f;
        rev->f -= f;
    }
};

int MaxPlate(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    int result = 0;
    while (true)
    {
        vector<int> p(n, -1);
        vector<Edge*> path(n);

        queue<int> Q;
        Q.push(s);

        while (!Q.empty() && p[t] == -1)
        {
            int u = Q.front();
            Q.pop();

            for (Edge* edge : graph[u])
            {
                int v = edge->v;
                int w = edge->Spare();

                if (w <= 0 || p[v] != -1)
                    continue;

                p[v] = u;
                path[v] = edge;
                Q.push(v);

                if (v == t)
                    break;
            }
        }

        if (p[t] == -1)
            break;

        int flow = INT_MAX;
        for (int i = t; i != s; i = p[i])
            flow = min(flow, path[i]->Spare());
        for (int i = t; i != s; i = p[i])
            path[i]->AddFLow(flow);
        result += flow;
    }

    return result;
}

int main()
{
    int n, k, d;
    cin >> n >> k >> d;

    vector<vector<Edge*>> graph(n * 2 + d + 2);
    int s = 0;
    int t = n * 2 + d + 1;
    for (int u = n * 2 + 1; u <= n * 2 + d; u++)
    {
        int c;
        cin >> c;

        Edge* e1 = new Edge(t, c);
        Edge* e2 = new Edge(u, 0);
        e1->rev = e2;
        e2->rev = e1;
        graph[u].push_back(e1);
        graph[t].push_back(e2);
    }

    for (int i = 1; i <= n; i++)
    {
        int u = i * 2 - 1;

        Edge* e1 = new Edge(u, INT_MAX);
        Edge* e2 = new Edge(s, 0);
        e1->rev = e2;
        e2->rev = e1;
        graph[s].push_back(e1);
        graph[u].push_back(e2);

        e1 = new Edge(u + 1, k);
        e2 = new Edge(u, 0);
        e1->rev = e2;
        e2->rev = e1;
        graph[u].push_back(e1);
        graph[u + 1].push_back(e2);

        int z;
        cin >> z;

        for (int i = 0; i < z; i++)
        {
            int v;
            cin >> v;
            v += n * 2;

            e1 = new Edge(v, 1);
            e2 = new Edge(u + 1, 0);
            e1->rev = e2;
            e2->rev = e1;
            graph[u + 1].push_back(e1);
            graph[v].push_back(e2);
        }
    }

    int result = MaxPlate(s, t, graph);
    cout << result << '\n';
}