#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void FW(vector<vector<int>>& graph)
{
    int n = graph.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j] != 0)
                    continue;

                if (graph[i][k] == graph[k][j])
                    graph[i][j] = graph[i][k];
            }
        }
    }
}

void CountMeasurableWeight(vector<int>& result, vector<vector<int>>& graph)
{
    FW(graph);

    int n = result.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            result[i] += (graph[i][j] == 0);
        result[i]--;
    }
}
int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        graph[a][b] = +1;
        graph[b][a] = -1;
    }

    vector<int> result(n, 0);
    CountMeasurableWeight(result, graph);
    for (int i = 0; i < n; i++)
        cout << result[i] << '\n';
}