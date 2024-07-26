#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 2> dy = { 0,1 };
array<int, 2> dx = { 1,0 };

struct Pos
{
    int y, x;
};

struct Edge
{
    int v;
    int c, f;
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

    static void AddEdge(int u, int v, int c2, int c1, vector<vector<Edge*>>& graph)
    {
        Edge* e1 = new Edge(v, c2);
        Edge* e2 = new Edge(u, c1);
        e1->rev = e2;
        e2->rev = e1;
        graph[u].push_back(e1);
        graph[v].push_back(e2);
    }
};

int MaxFlow(int s, int t, vector<vector<Edge*>>& graph)
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
        for (int i = t; i != s; i = p[i])
            path[i]->AddFlow(flow);
        result += flow;
    }
    return result;
}

int MinWall(vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<Edge*>> graph(n * m * 2);
    Pos s = { -1,-1 }, t = { -1,-1 };
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (map[y][x] == '#')
                continue;

            int u = (y * m + x) * 2;
            Edge::AddEdge(u, u + 1, 1, 0, graph);

            if (map[y][x] == 'K')
                s = { y,x };
            if (map[y][x] == 'H')
                t = { y,x };

            for (int i = 0; i < 2; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny >= n || nx >= m)
                    continue;
                if (map[ny][nx] == '#')
                    continue;

                int v = (ny * m + nx) * 2;
                Edge::AddEdge(u + 1, v, 1, 0, graph);
                Edge::AddEdge(v + 1, u, 1, 0, graph);
            }
        }
    }

    int result = -1;
    if (abs(s.y - t.y) + abs(s.x - t.x) > 1)
        result = MaxFlow((s.y * m + s.x) * 2 + 1, (t.y * m + t.x) * 2, graph);

    for (auto& edges : graph)
    {
        for (Edge* edge : edges)
            delete edge;
    }

    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    int result = MinWall(map);
    cout << result << '\n';
}