#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, w;
};

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> graph(n * k);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    
}