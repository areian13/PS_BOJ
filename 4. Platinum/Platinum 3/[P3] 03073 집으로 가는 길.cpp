#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

struct Pos
{
    int y, x;
};

struct Edge
{
    int v, c, f, d;
    Edge* rev;

    Edge() : Edge(-1, 0, 0) {}
    Edge(int v, int c, int d) : v(v), c(c), f(0), d(d), rev(nullptr) {}

    int Spare()
    {
        return c - f;
    }
    void AddFlow(int flow)
    {
        f += flow;
        rev->f -= flow;
    }

    static void AddEdge(int u, int v, int c1, int d1, int c2, int d2,
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

array<int, 2> MCMF(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    array<int, 2> result = { 0,0 };
    while (true)
    {
        vector<int> p(n, -1), dist(n, INT_MAX);
        dist[s] = 0;
        vector<Edge*> path(n);

        queue<int> Q;
        Q.push(s);

        vector<bool> inQ(n, false);
        inQ[s] = true;

        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            inQ[u] = false;

            for (Edge* edge : graph[u])
            {
                int v = edge->v;
                int nd = dist[u] + edge->d;

                if (edge->Spare() <= 0 || dist[v] <= nd)
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

        int flow = INT_MAX;
        for (int i = t; i != s; i = p[i])
            flow = min(flow, path[i]->Spare());
        for (int i = t; i != s; i = p[i])
        {
            result[1] += path[i]->d * flow;
            path[i]->AddFlow(flow);
        }
        result[0] += flow;
    }

    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        vector<vector<char>> map(n, vector<char>(m));
        vector<vector<int>> idx(n, vector<int>(m, -1));
        int k = 0, h = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> map[i][j];

                if (map[i][j] == 'm')
                    idx[i][j] = k++;
                if (map[i][j] == 'H')
                    idx[i][j] = h++;
            }
        }

        vector<vector<Edge*>> graph(k + h + 2);
        int s = k + h;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] != 'm')
                    continue;

                int u = idx[i][j];
                Edge::AddEdge(s, u, 1, 0, 0, 0, graph);

                vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
                dist[i][j] = 0;

                queue<Pos> Q;
                Q.push({ i,j });

                while (!Q.empty())
                {
                    int y = Q.front().y;
                    int x = Q.front().x;
                    Q.pop();

                    if (map[y][x] == 'H')
                    {
                        int v = idx[y][x] + k;
                        int d = dist[y][x];
                        Edge::AddEdge(u, v, 1, d, 0, -d, graph);
                    }

                    for (int l = 0; l < 4; l++)
                    {
                        int ny = y + dy[l];
                        int nx = x + dx[l];

                        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                            continue;
                        if (dist[ny][nx] != INT_MAX)
                            continue;

                        dist[ny][nx] = dist[y][x] + 1;
                        Q.push({ ny,nx });
                    }
                }
            }
        }

        int t = s + 1;
        for (int i = 0; i < h; i++)
        {
            int v = k + i;
            Edge::AddEdge(v, t, 1, 0, 0, 0, graph);
        }

        array<int, 2> result = MCMF(s, t, graph);
        cout << result[1] << '\n';
        Edge::DeleteEdge(graph);
    }
}