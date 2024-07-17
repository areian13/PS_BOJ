#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

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
};

int MaxOperate(int s, int t, vector<vector<Edge*>>& graph)
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
            path[i]->AddFlow(flow);
        result += flow;
    }
    return result;
}

int MinOperate(vector<vector<int>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<Edge*>> graph(n * m + 2);
    int s = n * m;
    int t = s + 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum += map[i][j];

            int u = i * m + j;
            bool isJ = ((i + j) % 2 == 0);
            int v = isJ ? s : t;

            Edge* e1 = new Edge(v, isJ ? 0 : map[i][j]);
            Edge* e2 = new Edge(u, isJ ? map[i][j] : 0);
            e1->rev = e2;
            e2->rev = e1;
            graph[u].push_back(e1);
            graph[v].push_back(e2);

            if (!isJ)
                continue;

            for (int k = 0; k < 4; k++)
            {
                int ni = i + dy[k];
                int nj = j + dx[k];

                if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                    continue;

                v = ni * m + nj;
                e1 = new Edge(v, INT_MAX);
                e2 = new Edge(u, 0);
                e1->rev = e2;
                e2->rev = e1;
                graph[u].push_back(e1);
                graph[v].push_back(e2);
            }
        }
    }

    int result = sum - MaxOperate(s, t, graph);

    for (int u = 0; u < n * m; u++)
    {
        for (Edge* edge : graph[u])
            delete edge;
    }
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

        vector<vector<int>> map(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> map[i][j];
        }

        int result = MinOperate(map);
        cout << result << '\n';
    }
}