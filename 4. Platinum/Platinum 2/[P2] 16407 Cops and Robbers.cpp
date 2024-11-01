#include <iostream>
#include <vector>
#include <climits>
#include <array>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const array<int, 4> dr = { 0,1,0,-1 };
const array<int, 4> dc = { 1,0,-1,0 };

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

    static void AddEdge(int u, int v, int c, vector<vector<Edge*>>& graph)
    {
        Edge* e1 = new Edge(v, c);
        Edge* e2 = new Edge(u, 0);
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

long long MaxFlow(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    long long result = 0;
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

                if (edge->Spare() <= 0 || p[v] != -1)
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

        result += flow;
        for (int i = t; i != s; i = p[i])
            path[i]->AddFlow(flow);
    }
    return result;
}

int main()
{
    FastIO;

    int n, m, c;
    cin >> n >> m >> c;

    vector<vector<char>> map(m, vector<char>(n));
    int s = -1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'B')
                s = (i * n + j) * 2;
        }
    }

    vector<int> cap(c);
    for (int i = 0; i < c; i++)
        cin >> cap[i];

    vector<vector<Edge*>> graph(m * n * 2 + 1);
    int t = m * n * 2;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int u = (i * n + j) * 2;
            int d = (map[i][j] == 'B' || map[i][j] == '.' ? INT_MAX : cap[map[i][j] - 'a']);
            Edge::AddEdge(u, u + 1, d, graph);

            for (int d = 0; d < 4; d++)
            {
                int nr = i + dr[d];
                int nc = j + dc[d];

                int v = (nr * n + nc) * 2;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                {
                    Edge::AddEdge(u + 1, t, INT_MAX, graph);
                    continue;
                }

                Edge::AddEdge(u + 1, v, INT_MAX, graph);
            }
        }
    }

    long long result = MaxFlow(s, t, graph);
    if (result >= INT_MAX)
        cout << -1 << '\n';
    else
        cout << result << '\n';
    Edge::DeleteEdge(graph);
}