#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

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
        p[min(u, v)] = max(u, v);
    }
};

void DFS(int p, int u, vector<bool>& isVisited, vector<vector<int>>& graph,
    int& cntCircle)
{
    for (int v : graph[u])
    {
        if (v == p)
            continue;
        if (isVisited[v])
        {
            cntCircle++;
            continue;
        }

        isVisited[v] = true;
        DFS(u, v, isVisited, graph, cntCircle);
    }
}

bool IsDimi(vector<vector<int>>& graph)
{
    int n = graph.size();

    int cnt3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (graph[i].size() > 3)
            return false;
        cnt3 += (graph[i].size() == 3);
    }

    if (cnt3 != 1)
        return false;

    int cntCircle = 0;
    vector<bool> isVisited(n, false);
    isVisited[0] = true;
    DFS(-1, 0, isVisited, graph, cntCircle);

    for (int i = 0; i < n; i++)
    {
        if (!isVisited[i])
            return false;
    }

    return (cntCircle == 2);
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    UnionFind uf(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool result = IsDimi(graph);
    if (result)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}