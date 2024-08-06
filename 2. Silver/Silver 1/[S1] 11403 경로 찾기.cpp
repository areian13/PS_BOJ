#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void FW(vector<vector<bool>>& graph)
{
    int n = graph.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
        }
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<bool>> graph(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool t;
            cin >> t;

            graph[i][j] = t;
        }
    }
    FW(graph);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << graph[i][j] << ' ';
        cout << '\n';
    }
}