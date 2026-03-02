#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
    }

    vector<double> water(n, 0);
    water[0] = 100;
    for (int u = 0; u < n; u++)
    {
        double k = graph[u].size();

        if (k == 0)
            continue;

        double w = water[u] / k;
        water[u] = 0;

        for (int v : graph[u])
            water[v] += w;
    }

    double result = *max_element(water.begin(), water.end());
    printf("%.6lf\n", result);
}