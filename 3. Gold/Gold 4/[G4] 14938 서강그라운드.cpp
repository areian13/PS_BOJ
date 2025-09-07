#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

void FW(vector<vector<int>>& graph)
{
    int n = graph.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][k] == INF || graph[k][j] == INF)
                    continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[j][k]);
            }
        }
    }
}

int main()
{
    FastIO;

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        graph[i][i] = 0;
    for (int i = 0; i < r; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    FW(graph);

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += c[j] * (graph[i][j] <= m);
        result = max(result, sum);
    }
    cout << result << '\n';
}