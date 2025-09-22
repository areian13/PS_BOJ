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
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main()
{
    FastIO;

    int n, d;
    cin >> n >> d;

    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
    {
        graph[i][i] = 0;
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;

            if (c == 'Y')
                graph[i][j] = 1;
        }
    }

    FW(graph);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            result = max(result, graph[i][j]);
    }

    if (result == INF)
        cout << -1 << '\n';
    else
        cout << result * d << '\n';
}