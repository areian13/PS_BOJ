#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct UnionFind
{
    vector<int> p;
    UnionFind(int n) { p.resize(n, -1); }
    int Find(int u) { return p[u] < 0 ? u : p[u] = Find(p[u]); }
    void Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if (u == v)
            return;
        if (p[u] > p[v])
            swap(u, v);
        p[u] += p[v], p[v] = u;
    }
};

void FW(vector<vector<int>>& graph)
{
    int n = graph.size();

    for (int i = 0; i < n; i++)
        graph[i][i] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][k] == INF || graph[k][j] == INF)
                    continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INF));
    UnionFind uf(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        uf.Union(u, v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    FW(graph);

    unordered_map<int, vector<int>> um;
    for (int i = 0; i < n; i++)
        um[uf.Find(i)].push_back(i);

    vector<int> result;
    for (auto& l : um)
    {
        int md = INF;
        int r = l.second[0];

        for (int u : l.second)
        {
            int d = 0;
            for (int v : l.second)
                d = max(d, graph[u][v]);

            if (d < md)
            {
                md = d;
                r = u;
            }
        }

        result.push_back(r);
    }
    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (int r : result)
        cout << r + 1 << '\n';
}