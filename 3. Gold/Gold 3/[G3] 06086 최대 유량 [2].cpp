#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 52

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
    void AddFlow(int f)
    {
        this->f += f;
        rev->f -= f;
    }
};

int ctoi(char c)
{
    if ('A' <= c && c <= 'Z')
        return c - 'A';
    return c - 'a' + 26;
}

int MaxFlow(int s, int t, array<vector<Edge*>, MAX>& graph)
{
    int result = 0;
    while (true)
    {
        array<int, MAX> p;
        fill(p.begin(), p.end(), -1);

        array<Edge*, MAX> path = { 0, };

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

                if(v == t)
                    break;
            }
        }

        if (p[t] == -1)
            break;

        int flow = INT_MAX;
        for (int i = t; i != s; i = p[i])
            flow = min(flow, path[i]->Spare());
        for (int i = t; i != s; i = p[i])
            path[i]->AddFlow(flow);
        result += flow;
    }

    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<vector<Edge*>, MAX> graph;
    for (int i = 0; i < n; i++)
    {
        char u, v;
        int w;
        cin >> u >> v >> w;
        u = ctoi(u), v = ctoi(v);

        Edge* e1 = new Edge(v, w);
        Edge* e2 = new Edge(u, w);
        e1->rev = e2;
        e2->rev = e1;

        graph[u].push_back(e1);
        graph[v].push_back(e2);
    }

    int s = ctoi('A');
    int t = ctoi('Z');
    int result = MaxFlow(s, t, graph);
    cout << result << '\n';

    for (int u = 0; u < MAX; u++)
    {
        for (Edge* edge : graph[u])
            delete edge;
    }
}