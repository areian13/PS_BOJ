#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Edge
{
    int v, w;
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    vector<vector<int>> mat(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        mat[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int s, e, l;
        cin >> s >> e >> l;
        s--, e--;

        mat[s][e] = min(mat[s][e], l);
        mat[e][s] = mat[s][e];
        graph[s].push_back({ e,l });
        graph[e].push_back({ s,l });
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
        for (int u = 0; u < n; u++)
        {
            maxT = max(maxT, 1. * mat[s][u]);
            for (auto& [v, w] : graph[u])
            {
                if (mat[s][u] + w <= mat[s][v])
                    continue;
                maxT = max(maxT, mat[s][u] + (w - abs(mat[s][v] - mat[s][u])) / 2.);
            }
        }
        result = min(result, maxT);
    }
    printf("%.1lf\n", result);
}