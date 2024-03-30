#include <iostream>
#include <vector>
#include <algorithm>

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
                if (i == j || graph[i][j] != 0)
                    continue;

                if (graph[i][k] == 1 && graph[k][j] == 1)
                    graph[i][j] = 2;
            }
        }
    }
}

int CountFamousMansFriend(vector<vector<int>>& graph)
{
    FW(graph);
    
    int n = graph.size();
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += (graph[i][j] != 0);
        result = max(result, cnt);
    }
    return result;
}

int main()
{
    FastIO;
    
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;

            graph[i][j] = (c == 'Y');
        }
    }

    int result = CountFamousMansFriend(graph);
    cout << result << '\n';
}