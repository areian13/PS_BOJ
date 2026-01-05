#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Edge
{
    int u, v, w;
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    vector<vector<int>> mat(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        mat[i][i] = 0;
    for (auto& [u, v, w] : edges)
    {
        cin >> u >> v >> w;
        u--, v--;

        mat[u][v] = min(mat[u][v], w);
        mat[v][u] = mat[u][v];
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (mat[i][k] == INF) continue;
            for (int j = 0; j < n; j++)
            {
                if (mat[k][j] == INF) continue;
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    double result = INF;
    for (int s = 0; s < n; s++)
    {
        double maxT = 0;
        for (auto& [u, v, w] : edges)
        {
            int dw = abs(mat[s][u] - mat[s][v]);
            maxT = max(maxT, max(mat[s][u], mat[s][v]) + (w - dw) / 2.);
        }
        result = min(result, maxT);
    }
    printf("%.1lf\n", result);
}