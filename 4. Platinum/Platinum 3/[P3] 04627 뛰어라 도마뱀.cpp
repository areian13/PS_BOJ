#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <queue>

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

bool CanGo(int s, int t, vector<int>& level, vector<vector<Edge*>>& graph)
{
    level[s] = 0;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (Edge* edge : graph[u])
        {
            int v = edge->v;

            if (edge->Spare() <= 0 || level[v] != INT_MAX)
                continue;

            level[v] = level[u] + 1;
            Q.push(v);
        }
    }

    return level[t] != INT_MAX;
}

int GetFlow(int u, int t, int flow, vector<int>& work,
    vector<int>& level, vector<vector<Edge*>>& graph)
{
    if (u == t)
        return flow;

    for (int& i = work[u]; i < graph[u].size(); i++)
    {
        Edge* edge = graph[u][i];
        int v = edge->v;

        if (edge->Spare() <= 0 || level[v] != level[u] + 1)
            continue;

        int tFLow = GetFlow(v, t, min(flow, edge->Spare()), work, level, graph);
        if (tFLow == 0)
            continue;

        edge->AddFlow(tFLow);
        return tFLow;
    }
    return 0;
}

int MaxEscape(int s, int t, vector<vector<Edge*>>& graph)
{
    int n = graph.size();

    int result = 0;
    while (true)
    {
        vector<int> level(n, INT_MAX);
        if (!CanGo(s, t, level, graph))
            break;

        vector<int> work(n, 0);
        int flow = GetFlow(s, t, INT_MAX, work, level, graph);
        if (flow == 0)
            break;
        result += flow;
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
        int n, d;
        cin >> n >> d;

        vector<string> map(n);
        for (int i = 0; i < n; i++)
            cin >> map[i];

        int m = map[0].size();
        
        vector<vector<Edge*>> graph(n * m * 2 + 2);
        int s = n * m * 2, t = s + 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == '0')
                    continue;

                int u = (i * m + j) * 2;
                Edge::AddEdge(u, u + 1, map[i][j] - '0', 0, graph);
                for (int y = i - d; y <= i + d; y++)
                {
                    for (int x = j - d; x <= j + d; x++)
                    {
                        if (y == i && x == j)
                            continue;
                        if (abs(y - i) + abs(x - j) > d)
                            continue;

                        bool isT = (y < 0 || y >= n || x < 0 || x >= m);
                        int v = isT ? t : (y * m + x) * 2;

                        if (!isT && map[y][x] == '0')
                            continue;

                        Edge::AddEdge(u + 1, v, INT_MAX, 0, graph);
                    }
                }
            }
        }

        int l = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char c;
                cin >> c;

                if (c != 'L')
                    continue;

                l++;
                int u = (i * m + j) * 2;
                Edge::AddEdge(s, u, 1, 0, graph);
            }
        }

        int result = l - MaxEscape(s, t, graph);
        if (result == 0)
            printf("Case #%d: no lizard was left behind.\n", ti);
        else if (result == 1)
            printf("Case #%d: 1 lizard was left behind.\n", ti);
        else
            printf("Case #%d: %d lizards were left behind.\n", ti, result);
        Edge::DeleteEdge(graph);
    }
}