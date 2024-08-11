#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF INT_MAX

void BFS(vector<bool>& isUsed, vector<int>& level, vector<int>& b,
    vector<vector<int>>& graph)
{
    int n = graph.size();

    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        if (isUsed[i])
            continue;

        level[i] = 0;
        Q.push(i);
    }

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : graph[u])
        {
            if (b[v] == -1 || level[b[v]] != INF)
                continue;

            level[b[v]] = level[u] + 1;
            Q.push(b[v]);
        }
    }
}

bool CanMatch(int u, vector<bool>& isUsed, vector<int>& a, vector<int>& b,
    vector<int>& level, vector<vector<int>>& graph)
{
    for (int v : graph[u])
    {
        if (b[v] != -1)
        {
            if (level[b[v]] != level[u] + 1)
                continue;
            if (!CanMatch(b[v], isUsed, a, b, level, graph))
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
        vector<int> level(n, INF);
        BFS(isUsed, level, b, graph);

        int flow = 0;
        for (int i = 0; i < n; i++)
            flow += (!isUsed[i] && CanMatch(i, isUsed, a, b, level, graph));

        if (flow == 0)
            break;

        result += flow;
    }
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        int n;
        
        if (scanf("%d", &n) == EOF)
            break;

        vector<vector<int>> graph(n);
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            int u, k;
            scanf("%d: (%d)", &u, &k);

            for (int i = 0; i < k; i++)
            {
                int v;
                scanf("%d", &v);

                m = max(m, v);
                graph[u].push_back(v - 1);
            }
        }

        int result = MaxMatch(n, m, graph);
        cout << result << '\n';
    }
}