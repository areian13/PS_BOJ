#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void MakeParent(int u, vector<int>& depth,
    vector<int>& parent, vector<vector<int>>& graph)
{
    for (int v : graph[u])
    {
        if (depth[v] != -1)
            continue;
        parent[v] = u;
        depth[v] = depth[u] + 1;
        MakeParent(v, depth, parent, graph);
    }
}

int LCA(int u, int v, vector<int>& depth, vector<int>& parent)
{
    if (depth[u] > depth[v])
        swap(u, v);
    while (depth[u] < depth[v])
        v = parent[v];

    while (u != v)
    {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> depth(n, -1), parent(n, -1);
    depth[0] = 0;
    MakeParent(0, depth, parent, graph);

    int m;
    cin >> m;

    for (int q = 1; q <= m; q++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        int result = LCA(u, v, depth, parent);
        cout << result + 1 << '\n';
    }
}