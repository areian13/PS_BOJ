#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void BFS(vector<bool>& isUsed, vector<int>& level,
    vector<int>& a, vector<int>& b, vector<vector<int>>& graph)
{
    int n = graph.size();

    queue<int> Q;
    for (int u = 0; u < n; u++)
    {
        if (isUsed[u])
            continue;

        level[u] = 0;
        Q.push(u);
    }

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : graph[u])
        {
            if (b[v] == -1 || level[b[v]] != INT_MAX)
                continue;

            level[b[v]] = level[u] + 1;
            Q.push(b[v]);
        }
    }
}

bool CanMatch(int u, vector<bool>& isUsed, vector<int>& level,
    vector<int>& a, vector<int>& b, vector<vector<int>>& graph)
{
    for (int v : graph[u])
    {
        if (b[v] != -1)
        {
            if (level[b[v]] != level[u] + 1)
                continue;
            if (!CanMatch(b[v], isUsed, level, a, b, graph))
                continue;
        }

        a[u] = v;
        b[v] = u;
        return isUsed[u] = true;
    }
    return false;
}

int MaxMatch(int n, int m, vector<vector<int>>& graph)
{
    vector<int> a(n, -1), b(m, -1);
    vector<bool> isUsed(n, false);
    int result = 0;
    while (true)
    {
        vector<int> level(n, INT_MAX);
        BFS(isUsed, level, a, b, graph);

        int flow = 0;
        for (int u = 0; u < n; u++)
            flow += (!isUsed[u] && CanMatch(u, isUsed, level, a, b, graph));

        if (flow == 0)
            break;

        result += flow;
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
    }

    int result = MaxMatch(n, n, graph);
    cout << result << '\n';
}