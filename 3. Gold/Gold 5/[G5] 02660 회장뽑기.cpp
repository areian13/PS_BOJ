#include <iostream>
#include <vector>
#include <climits>

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
                if (graph[i][k] == INT_MAX || graph[k][j] == INT_MAX)
                    continue;

                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
    while (true)
    {
        int a, b;
        cin >> a >> b;

        if (a == -1 && b == -1)
            break;

        a--, b--;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    FW(graph);

    vector<int> scores(n, 0);
    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        graph[i][i] = 0;
        for (int j = 0; j < n; j++)
            scores[i] = max(scores[i], graph[i][j]);
        result = min(result, scores[i]);
    }

    vector<int> cand;
    for (int i = 0; i < n; i++)
    {
        if (scores[i] == result)
            cand.push_back(i);
    }

    int k = cand.size();
    cout << result << ' ' << k << '\n';
    for (int i = 0; i < k; i++)
        cout << cand[i] + 1 << ' ';
    cout << '\n';
}