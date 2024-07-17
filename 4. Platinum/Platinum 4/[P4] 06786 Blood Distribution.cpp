#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define BLOOD 8

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

int MaxBlood(int s, int t, vector<vector<Edge*>>& graph)
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
    FastIO;

    vector<vector<int>> edges =
    {
        { 0,1,2,3,4,5,6,7 }, // O-
        { 1,3,5,7 },         // O+
        { 2,3,6,7 },         // A-
        { 3,7 },             // A+
        { 4,5,6,7 },         // B-
        { 5,7 },             // B+
        { 6,7 },             // AB-
        { 7 }                // AB+
    };

    vector<vector<Edge*>> graph(BLOOD * 2 + 2);
    int s = BLOOD * 2;
    int t = s + 1;
    for (int i = 0; i < BLOOD; i++)
    {
        int h;
        cin >> h;

        int u = i * 2;

        Edge* e1 = new Edge(u, h);
        Edge* e2 = new Edge(s, 0);
        e1->rev = e2;
        e2->rev = e1;
        graph[s].push_back(e1);
        graph[u].push_back(e2);

        for (int v : edges[i])
        {
            v = v * 2 + 1;

            e1 = new Edge(v, INT_MAX);
            e2 = new Edge(u, 0);
            e1->rev = e2;
            e2->rev = e1;
            graph[u].push_back(e1);
            graph[v].push_back(e2);
        }
    }

    for (int i = 0; i < BLOOD; i++)
    {
        int p;
        cin >> p;

        int u = i * 2 + 1;

        Edge* e1 = new Edge(t, p);
        Edge* e2 = new Edge(u, 0);
        e1->rev = e2;
        e2->rev = e1;
        graph[u].push_back(e1);
        graph[t].push_back(e2);
    }

    int result = MaxBlood(s, t, graph);
    cout << result << '\n';
}