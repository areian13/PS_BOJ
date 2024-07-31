#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 6> dy = { -1,0,1,-1,0,1 };
array<int, 6> dx = { -1,-1,-1,1,1,1 };

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

        for (int i = t; i != s; i = p[i])
            path[i]->AddFlow(+1);
        result += 1;
    }
    return result;
}

int MaxStu(vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<Edge*>> graph(n * m + 2);
    int s = n * m;
    int t = s + 1;
    int k = 0;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (map[y][x] == 'x')
                continue;

            k++;
            int u = y * m + x;
            if (x % 2 == 0)
            {
                Edge::AddEdge(s, u, 1, 0, graph);

                for (int i = 0; i < 6; i++)
                {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                        continue;
                    if (map[ny][nx] == 'x')
                        continue;

                    int v = ny * m + nx;
                    Edge::AddEdge(u, v, 1, 0, graph);
                }
            }
            else
                Edge::AddEdge(u, t, 1, 0, graph);
        }
    }

    int result = k - MaxFlow(s, t, graph);
    Edge::DeleteEdge(graph);
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> map(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> map[i][j];
        }

        int result = MaxStu(map);
        cout << result << '\n';
    }
}