#include <iostream>
#include <vector>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void MakeParent(int u, vector<int>& depth,
    vector<vector<int>>& parent, vector<vector<int>>& graph)
{
    for (int v : graph[u])
    {
        if (depth[v] != -1)
            continue;

        parent[v][0] = u;
        depth[v] = depth[u] + 1;
        MakeParent(v, depth, parent, graph);
    }
}

int LCA(int u, int v, vector<int>& depth, vector<vector<int>>& parent)
{
    if (depth[u] > depth[v])
        swap(u, v);
    while (depth[u] < depth[v])
    {
        int i = 0;
        while (depth[u] < depth[parent[v][i + 1]])
            i++;
        v = parent[v][i];
    }

    while (u != v)
    {
        int i = 0;
        while (parent[u][i + 1] != parent[v][i + 1])
            i++;
        u = parent[u][i];
        v = parent[v][i];
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

    int k = bit_width((unsigned)n);
    vector<int> depth(n, -1);
    vector<vector<int>> parent(n, vector<int>(k, -1));
    depth[0] = 0;
    MakeParent(0, depth, parent, graph);

    for (int j = 1; j < k; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (parent[i][j - 1] != -1)
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

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