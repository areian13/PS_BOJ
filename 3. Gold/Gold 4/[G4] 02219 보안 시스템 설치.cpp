#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        edge[a][b] = c;
        edge[b][a] = c;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (edge[i][k] != INT_MAX && edge[k][j] != INT_MAX)
                    edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }

    int result = 0;
    int minDist = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int dist = 0;
        for (int j = 0; j < n; j++)
            dist += edge[i][j];

        if (dist < minDist)
        {
            minDist = dist;
            result = i + 1;
        }
    }
    cout << result << '\n';
}