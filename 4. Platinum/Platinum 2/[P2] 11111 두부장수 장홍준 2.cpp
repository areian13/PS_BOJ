#include <iostream>
#include <vector>
#include <climits>
#include <array>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dr = { 0,1,0,-1 };
array<int, 4> dc = { 1,0,-1,0 };

struct Edge
{
    int v;
    int c, f, d;
    Edge* rev;

    Edge() : Edge(-1, 0, 0) {}
    Edge(int v, int c, int d) : v(v), c(c), f(0), d(d), rev(nullptr) {}

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

    static void AddEdge(int u, int v, int c, int d,
        vector<vector<Edge*>>& graph)
    {
        Edge* e1 = new Edge(v, c, d);
        Edge* e2 = new Edge(u, 0, -d);
        e1->rev = e2;
        e2->rev = e1;
        graph[u].push_back(e1);
        graph[v].push_back(e2);
    }
    static void DeleteEdge(vector<vector<Edge*>>& graph)
    {
        for (auto edges : graph)
        {
            for (Edge* edge : edges)
                delete edge;
        }
    }
};

int Score(char a, char b)
{
    static array<array<int, 6>, 6> score =
    {
        array<int, 6>
        { 10,8,7,5,0,1 },
        { 8,6,4,3,0,1 },
        { 7,4,3,2,0,1 },
        { 5,3,2,2,0,1 },
        { 0,0,0,0,0,0 },
        { 1,1,1,1,0,0 },
    };

    return score[a - 'A'][b - 'A'];
}

int MaxTofuPrice(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    array<int, 2> result = { 0,0 };
    while (true)
    {
        vector<int> p(n, -1);
        vector<int> dist(n, INT_MIN);
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
                int nd = dist[u] + edge->d;

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

        int flow = INT_MAX;
        for (int i = t; i != s; i = p[i])
            flow = min(flow, path[i]->Spare());
        
        for (int i = t; i != s; i = p[i])
        {
            result[1] += flow * path[i]->d;
            path[i]->AddFlow(flow);
        }
        result[0] = max(result[0], result[1]);
    }
    return result[0];
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

    vector<vector<Edge*>> graph(n * m + 2);
    int s = n * m, t = s + 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = i * m + j;

            if ((i + j) % 2 == 0)
                Edge::AddEdge(s, u, 1, 0, graph);
            else
            {
                Edge::AddEdge(u, t, 1, 0, graph);
                continue;
            }

            for (int k = 0; k < 4; k++)
            {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                int v = nr * m + nc;
                int d = Score(map[i][j], map[nr][nc]);
                Edge::AddEdge(u, v, 1, d, graph);
            }
        }
    }

    int result = MaxTofuPrice(s, t, graph);
    cout << result << '\n';
    Edge::DeleteEdge(graph);
}