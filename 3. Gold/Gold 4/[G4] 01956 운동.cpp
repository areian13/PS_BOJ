#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int v, e;
    cin >> v >> e;

    vector<vector<int>> edge(v, vector<int>(v, INT_MAX));
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        edge[a][b] = c;
    }

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (edge[i][k] != INT_MAX && edge[k][j] != INT_MAX)
                    edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }

    int result = INT_MAX;
    for (int i = 0; i < v; i++)
    {
        for (int j = i + 1; j < v; j++)
        {
            if (edge[i][j] == INT_MAX || edge[j][i] == INT_MAX)
                continue;

            result = min(result, edge[i][j] + edge[j][i]);
        }
    }

    if (result != INT_MAX)
        cout << result << '\n';
    else
        cout << -1 << '\n';
}