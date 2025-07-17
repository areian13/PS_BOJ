#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool DFS(int u, vector<int>& dist, vector<vector<int>>& graph)
{
    for (int v : graph[u])
    {
        if (dist[v] != -1)
        {
            if (dist[v] % 2 == dist[u] % 2)
                return false;
            continue;
        }

        dist[v] = dist[u] + 1;
        if (!DFS(v, dist, graph))
            return false;
    }
    return true;
}

bool AnemyOfAnemy(vector<vector<int>>& graph)
{
    int n = graph.size();

    vector<int> dist(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (dist[i] != -1)
            continue;

        dist[i] = 0;
        if (!DFS(i, dist, graph))
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool result = AnemyOfAnemy(graph);
    cout << result << '\n';
}